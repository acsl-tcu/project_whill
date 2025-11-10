#!/usr/bin/env python3
"""
Convert Markdown to HTML with Mermaid diagram support
Creates an HTML file you can open in a browser and then print to PDF
"""

import sys
import os
import re

def convert_markdown_to_html_with_mermaid(md_file_path):
    """Convert markdown file to HTML with Mermaid.js support"""

    # Read markdown content
    with open(md_file_path, 'r', encoding='utf-8') as f:
        md_content = f.read()

    # Convert markdown to HTML preserving mermaid blocks
    html_body = convert_md_to_html(md_content)

    # Wrap in full HTML document with Mermaid support
    html_template = f"""<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Wheelchair Navigation System - Simple Explanation</title>

    <!-- Mermaid.js from CDN -->
    <script src="https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.min.js"></script>
    <script>
        // Initialize Mermaid when page loads
        document.addEventListener('DOMContentLoaded', function() {{
            mermaid.initialize({{
                startOnLoad: true,
                theme: 'default',
                flowchart: {{
                    useMaxWidth: true,
                    htmlLabels: true,
                    curve: 'basis',
                    padding: 20
                }},
                themeVariables: {{
                    fontSize: '16px'
                }}
            }});
        }});
    </script>

    <style>
        @media print {{
            @page {{
                size: A4;
                margin: 1.5cm;
            }}
            body {{
                margin: 0;
            }}
            .mermaid {{
                page-break-inside: avoid;
            }}
            h1, h2, h3 {{
                page-break-after: avoid;
            }}
        }}

        body {{
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif;
            line-height: 1.6;
            color: #333;
            max-width: 1000px;
            margin: 0 auto;
            padding: 40px 20px;
            font-size: 14px;
        }}

        h1 {{
            border-bottom: 3px solid #0366d6;
            padding-bottom: 12px;
            color: #24292e;
            font-size: 32px;
            margin-top: 24px;
            margin-bottom: 16px;
        }}

        h2 {{
            color: #24292e;
            margin-top: 32px;
            margin-bottom: 16px;
            border-bottom: 2px solid #eaecef;
            padding-bottom: 8px;
            font-size: 24px;
        }}

        h3 {{
            color: #24292e;
            margin-top: 24px;
            margin-bottom: 16px;
            font-size: 20px;
        }}

        h4 {{
            color: #24292e;
            margin-top: 20px;
            margin-bottom: 12px;
            font-size: 16px;
        }}

        p {{
            margin: 12px 0;
        }}

        code {{
            background: #f6f8fa;
            padding: 3px 6px;
            border-radius: 3px;
            font-family: 'SF Mono', 'Monaco', 'Courier New', monospace;
            font-size: 85%;
        }}

        pre {{
            background: #f6f8fa;
            padding: 16px;
            border-radius: 6px;
            overflow-x: auto;
            border: 1px solid #e1e4e8;
            line-height: 1.45;
            margin: 16px 0;
        }}

        pre code {{
            background: transparent;
            padding: 0;
            border-radius: 0;
        }}

        table {{
            border-collapse: collapse;
            width: 100%;
            margin: 20px 0;
            display: table;
        }}

        th, td {{
            border: 1px solid #d0d7de;
            padding: 8px 13px;
            text-align: left;
        }}

        th {{
            background-color: #f6f8fa;
            font-weight: 600;
        }}

        tr:nth-child(even) {{
            background-color: #f6f8fa;
        }}

        .mermaid {{
            background: white;
            padding: 20px;
            margin: 30px 0;
            border: 2px solid #e1e4e8;
            border-radius: 8px;
            text-align: center;
        }}

        hr {{
            border: none;
            border-top: 2px solid #e1e4e8;
            margin: 40px 0;
        }}

        ul, ol {{
            margin: 12px 0;
            padding-left: 32px;
        }}

        li {{
            margin: 6px 0;
        }}

        strong {{
            font-weight: 600;
            color: #24292e;
        }}

        blockquote {{
            border-left: 4px solid #dfe2e5;
            padding-left: 16px;
            color: #6a737d;
            margin: 16px 0;
        }}

        a {{
            color: #0366d6;
            text-decoration: none;
        }}

        a:hover {{
            text-decoration: underline;
        }}

        /* Print button */
        .print-button {{
            position: fixed;
            top: 20px;
            right: 20px;
            padding: 12px 24px;
            background: #0366d6;
            color: white;
            border: none;
            border-radius: 6px;
            cursor: pointer;
            font-size: 14px;
            font-weight: 600;
            box-shadow: 0 2px 8px rgba(0,0,0,0.15);
            z-index: 1000;
        }}

        .print-button:hover {{
            background: #0256c7;
        }}

        @media print {{
            .print-button {{
                display: none;
            }}
        }}
    </style>
</head>
<body>
    <button class="print-button" onclick="window.print()">🖨️ Print to PDF</button>

{html_body}

    <script>
        // Log when Mermaid finishes rendering
        mermaid.init(undefined, document.querySelectorAll('.mermaid'));
        console.log('Mermaid diagrams rendered successfully');
    </script>
</body>
</html>"""

    return html_template

def convert_md_to_html(md_text):
    """Convert markdown to HTML, preserving mermaid code blocks"""
    lines = md_text.split('\n')
    html_lines = []
    in_code_block = False
    in_mermaid_block = False
    code_buffer = []

    i = 0
    while i < len(lines):
        line = lines[i]

        # Check for mermaid code block start
        if line.strip() == '```mermaid':
            in_mermaid_block = True
            in_code_block = True
            code_buffer = []
            i += 1
            continue

        # Check for regular code block start
        if line.startswith('```') and not in_code_block:
            in_code_block = True
            lang = line.replace('```', '').strip()
            if lang:
                html_lines.append(f'<pre><code class="language-{lang}">')
            else:
                html_lines.append('<pre><code>')
            i += 1
            continue

        # Check for code block end
        if line.startswith('```') and in_code_block:
            if in_mermaid_block:
                # Close mermaid block
                mermaid_code = '\n'.join(code_buffer)
                html_lines.append(f'<div class="mermaid">\n{mermaid_code}\n</div>')
                in_mermaid_block = False
            else:
                # Close regular code block
                html_lines.append('</code></pre>')
            in_code_block = False
            i += 1
            continue

        # Handle content inside code blocks
        if in_code_block:
            if in_mermaid_block:
                code_buffer.append(line)
            else:
                html_lines.append(line)
            i += 1
            continue

        # Convert markdown elements
        # Headers
        if line.startswith('#### '):
            html_lines.append(f'<h4>{line[5:]}</h4>')
        elif line.startswith('### '):
            html_lines.append(f'<h3>{line[4:]}</h3>')
        elif line.startswith('## '):
            html_lines.append(f'<h2>{line[3:]}</h2>')
        elif line.startswith('# '):
            html_lines.append(f'<h1>{line[2:]}</h1>')

        # Horizontal rule
        elif line.strip() == '---':
            html_lines.append('<hr>')

        # Unordered list
        elif line.strip().startswith('- '):
            content = line.strip()[2:]
            content = apply_inline_formatting(content)
            if i == 0 or not lines[i-1].strip().startswith('- '):
                html_lines.append('<ul>')
            html_lines.append(f'<li>{content}</li>')
            if i + 1 >= len(lines) or not lines[i+1].strip().startswith('- '):
                html_lines.append('</ul>')

        # Ordered list
        elif re.match(r'^\d+\.\s', line.strip()):
            content = re.sub(r'^\d+\.\s', '', line.strip())
            content = apply_inline_formatting(content)
            if i == 0 or not re.match(r'^\d+\.\s', lines[i-1].strip()):
                html_lines.append('<ol>')
            html_lines.append(f'<li>{content}</li>')
            if i + 1 >= len(lines) or not re.match(r'^\d+\.\s', lines[i+1].strip()):
                html_lines.append('</ol>')

        # Table detection (simplified)
        elif '|' in line and i + 1 < len(lines) and '|' in lines[i+1]:
            # Start table
            html_lines.append('<table>')
            # Header row
            cells = [c.strip() for c in line.split('|') if c.strip()]
            html_lines.append('<thead><tr>')
            for cell in cells:
                html_lines.append(f'<th>{apply_inline_formatting(cell)}</th>')
            html_lines.append('</tr></thead>')

            # Skip separator line
            i += 1
            if i < len(lines) and lines[i].strip().startswith('|'):
                i += 1

            # Body rows
            html_lines.append('<tbody>')
            while i < len(lines) and '|' in lines[i]:
                cells = [c.strip() for c in lines[i].split('|') if c.strip()]
                html_lines.append('<tr>')
                for cell in cells:
                    html_lines.append(f'<td>{apply_inline_formatting(cell)}</td>')
                html_lines.append('</tr>')
                i += 1
            html_lines.append('</tbody></table>')
            continue

        # Empty line
        elif line.strip() == '':
            html_lines.append('<p></p>')

        # Regular paragraph
        else:
            formatted_line = apply_inline_formatting(line)
            html_lines.append(f'<p>{formatted_line}</p>')

        i += 1

    return '\n'.join(html_lines)

def apply_inline_formatting(text):
    """Apply inline markdown formatting (bold, italic, code, links)"""
    # Bold
    text = re.sub(r'\*\*(.+?)\*\*', r'<strong>\1</strong>', text)

    # Italic
    text = re.sub(r'\*(.+?)\*', r'<em>\1</em>', text)

    # Inline code
    text = re.sub(r'`(.+?)`', r'<code>\1</code>', text)

    # Links [text](url)
    text = re.sub(r'\[(.+?)\]\((.+?)\)', r'<a href="\2">\1</a>', text)

    return text

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 create_html_with_mermaid.py <markdown_file>")
        print("Example: python3 create_html_with_mermaid.py Reference/Wheelchair_Navigation_Simple_Explanation.md")
        sys.exit(1)

    md_file = sys.argv[1]

    if not os.path.exists(md_file):
        print(f"Error: File not found: {md_file}")
        sys.exit(1)

    # Output HTML file
    html_file = md_file.replace('.md', '.html')

    print(f"Converting {md_file} to HTML with Mermaid support...")

    # Convert to HTML
    html_content = convert_markdown_to_html_with_mermaid(md_file)

    # Write HTML file
    with open(html_file, 'w', encoding='utf-8') as f:
        f.write(html_content)

    print(f"✅ HTML created successfully: {html_file}")
    print(f"\nTo view and print to PDF:")
    print(f"1. Open the HTML file in your browser (Chrome/Firefox/Edge)")
    print(f"2. Wait for Mermaid diagrams to render (~2 seconds)")
    print(f"3. Click the 'Print to PDF' button (or press Ctrl+P)")
    print(f"4. Select 'Save as PDF' as the printer")
    print(f"5. Save your PDF!")
    print(f"\nOpening in browser...")

    # Try to open in browser
    html_path = os.path.abspath(html_file)
    try:
        import subprocess
        subprocess.Popen(['xdg-open', html_path])
    except:
        print(f"\nManually open: file://{html_path}")

if __name__ == '__main__':
    main()
