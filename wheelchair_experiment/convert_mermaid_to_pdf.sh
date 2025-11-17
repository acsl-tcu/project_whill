#!/bin/bash
# Convert Markdown with Mermaid to PDF using Chrome
# This script creates an HTML file with Mermaid support, then converts to PDF

INPUT_FILE="$1"
if [ -z "$INPUT_FILE" ]; then
    INPUT_FILE="Reference/Wheelchair_Navigation_Simple_Explanation.md"
fi

OUTPUT_FILE="${INPUT_FILE%.md}.pdf"
TEMP_HTML="${INPUT_FILE%.md}_temp.html"

echo "Converting $INPUT_FILE to PDF with Mermaid support..."

# Read the markdown file and create HTML with Mermaid support
cat > "$TEMP_HTML" << 'EOF_HEADER'
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Wheelchair Navigation System</title>
    <script type="module">
        import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
        mermaid.initialize({
            startOnLoad: true,
            theme: 'default',
            flowchart: {
                useMaxWidth: true,
                htmlLabels: true,
                curve: 'basis'
            }
        });
    </script>
    <style>
        body {
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif;
            line-height: 1.6;
            color: #333;
            max-width: 900px;
            margin: 0 auto;
            padding: 20px;
        }
        h1 {
            border-bottom: 2px solid #eee;
            padding-bottom: 10px;
            color: #2c3e50;
        }
        h2 {
            color: #34495e;
            margin-top: 30px;
            border-bottom: 1px solid #eee;
            padding-bottom: 5px;
        }
        h3 {
            color: #555;
            margin-top: 20px;
        }
        code {
            background: #f4f4f4;
            padding: 2px 6px;
            border-radius: 3px;
            font-family: 'Courier New', monospace;
        }
        pre {
            background: #f6f8fa;
            padding: 16px;
            border-radius: 6px;
            overflow-x: auto;
            border: 1px solid #d1d5da;
        }
        table {
            border-collapse: collapse;
            width: 100%;
            margin: 20px 0;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 12px;
            text-align: left;
        }
        th {
            background-color: #f6f8fa;
            font-weight: 600;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        .mermaid {
            background: white;
            padding: 20px;
            margin: 20px 0;
            border: 1px solid #e1e4e8;
            border-radius: 6px;
        }
        hr {
            border: none;
            border-top: 1px solid #eee;
            margin: 30px 0;
        }
        ul, ol {
            margin: 10px 0;
            padding-left: 30px;
        }
        li {
            margin: 5px 0;
        }
        strong {
            font-weight: 600;
            color: #24292e;
        }
        blockquote {
            border-left: 4px solid #dfe2e5;
            padding-left: 16px;
            color: #6a737d;
            margin: 0;
        }
    </style>
</head>
<body>
EOF_HEADER

# Use markdown to convert the file to HTML (preserving mermaid blocks)
if command -v marked &> /dev/null; then
    marked "$INPUT_FILE" >> "$TEMP_HTML"
else
    # Simple markdown conversion using sed (basic)
    echo "<div class='markdown-body'>" >> "$TEMP_HTML"

    # Convert markdown to HTML (basic conversion)
    sed 's/^# \(.*\)/<h1>\1<\/h1>/g;
         s/^## \(.*\)/<h2>\1<\/h2>/g;
         s/^### \(.*\)/<h3>\1<\/h3>/g;
         s/^#### \(.*\)/<h4>\1<\/h4>/g;
         s/^\*\*\(.*\)\*\*/<strong>\1<\/strong>/g;
         s/^---$/<hr>/g;
         s/^- \(.*\)/<li>\1<\/li>/g' "$INPUT_FILE" >> "$TEMP_HTML"

    echo "</div>" >> "$TEMP_HTML"
fi

# Close HTML
cat >> "$TEMP_HTML" << 'EOF_FOOTER'
</body>
</html>
EOF_FOOTER

echo "Created temporary HTML file: $TEMP_HTML"

# Wait for mermaid to render, then convert to PDF using Chrome
echo "Converting to PDF using Chrome..."
google-chrome --headless --disable-gpu --print-to-pdf="$OUTPUT_FILE" \
    --no-pdf-header-footer \
    --print-to-pdf-no-header \
    "file://$(realpath $TEMP_HTML)" 2>/dev/null

# Wait a moment for rendering
sleep 2

if [ -f "$OUTPUT_FILE" ]; then
    echo "✓ PDF created successfully: $OUTPUT_FILE"
    echo "✓ Cleaning up temporary HTML file..."
    rm "$TEMP_HTML"
else
    echo "✗ PDF creation failed"
    echo "  Temporary HTML file kept for debugging: $TEMP_HTML"
    exit 1
fi
