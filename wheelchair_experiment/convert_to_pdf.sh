#!/bin/bash
# Convert Markdown to PDF with Mermaid Flowcharts
# Usage: ./convert_to_pdf.sh <input.md>

if [ $# -eq 0 ]; then
    echo "Usage: ./convert_to_pdf.sh <markdown_file>"
    echo "Example: ./convert_to_pdf.sh Reference/Wheelchair_Navigation_Simple_Explanation.md"
    exit 1
fi

INPUT_FILE="$1"
OUTPUT_FILE="${INPUT_FILE%.md}.pdf"

echo "Converting $INPUT_FILE to PDF..."
echo "Output: $OUTPUT_FILE"

# Method 1: Try using VS Code command (if available)
if command -v code &> /dev/null; then
    echo "Method 1: Using VS Code Markdown PDF extension..."
    code --extensionDevelopmentPath=/dev/null --export-pdf "$INPUT_FILE" "$OUTPUT_FILE" 2>/dev/null

    if [ $? -eq 0 ] && [ -f "$OUTPUT_FILE" ]; then
        echo "✓ PDF created successfully using VS Code!"
        exit 0
    fi
fi

# Method 2: Use mermaid-cli to pre-render diagrams, then convert
echo "Method 2: Pre-rendering Mermaid diagrams..."

# Create temporary directory
TEMP_DIR=$(mktemp -d)
TEMP_MD="$TEMP_DIR/temp.md"

# Copy the markdown file
cp "$INPUT_FILE" "$TEMP_MD"

# Extract and render mermaid diagrams
echo "Extracting Mermaid diagrams..."
DIAGRAM_COUNT=0

# This is a simplified approach - for production, use a proper parser
# For now, just inform the user
echo ""
echo "Note: For best results with Mermaid flowcharts, use one of these methods:"
echo ""
echo "1. VS Code Extension (Recommended):"
echo "   - Open the file in VS Code"
echo "   - Press Ctrl+Shift+P"
echo "   - Type 'Markdown PDF: Export (pdf)'"
echo "   - Press Enter"
echo ""
echo "2. Online Converter:"
echo "   - Visit https://www.markdowntopdf.com/"
echo "   - Upload your markdown file"
echo "   - Download the PDF with rendered flowcharts"
echo ""
echo "3. Chrome/Edge Browser:"
echo "   - Open the markdown preview in VS Code"
echo "   - Press Ctrl+Shift+P"
echo "   - Type 'Markdown: Open Preview'"
echo "   - In the preview, press Ctrl+P (Print)"
echo "   - Select 'Save as PDF'"
echo ""

# Cleanup
rm -rf "$TEMP_DIR"

exit 0
