#!/usr/bin/env python3
"""
Convert Markdown to PDF with Mermaid diagram support
Uses markdown library to convert MD to HTML, then Chrome to render PDF
"""

import sys
import os
import re
import subprocess
from pathlib import Path

def convert_markdown_to_html_with_mermaid(md_file_path):
    """Convert markdown file to HTML with Mermaid.js support"""

    # Read markdown content
    with open(md_file_path, 'r', encoding='utf-8') as f:
        md_content = f.read()

    # Try to use markdown library if available, otherwise basic conversion
    try:
        import markdown
        # Convert markdown to HTML (excluding mermaid blocks)
        # We'll handle mermaid blocks separately
        html_content = markdown.markdown(md_content, extensions=['tables', 'fenced_code'])
    except ImportError:
        # Basic markdown conversion
        html_content = basic_markdown_to_html(md_content)

    # Wrap in full HTML document with Mermaid support
    html_template = f"""<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Wheelchair Navigation System</title>
    <script type="module">
        import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
        mermaid.initialize({{
            startOnLoad: true,
            theme: 'default',
            flowchart: {{
                useMaxWidth: true,
                htmlLabels: true,
                curve: 'basis',
                padding: 20
            }}
        }});
    </script>
    <style>
        @page {{
            size: A4;
            margin: 2cm;
        }}
        body {{
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif;
            line-height: 1.6;
            color: #333;
            max-width: 900px;
            margin: 0 auto;
            padding: 20px;
            font-size: 11pt;
        }}
        h1 {{
            border-bottom: 2px solid #eee;
            padding-bottom: 10px;
            color: #2c3e50;
            font-size: 28pt;
            margin-top: 20px;
        }}
        h2 {{
            color: #34495e;
            margin-top: 30px;
            border-bottom: 1px solid #eee;
            padding-bottom: 5px;
            font-size: 20pt;
            page-break-after: avoid;
        }}
        h3 {{
            color: #555;
            margin-top: 20px;
            font-size: 16pt;
            page-break-after: avoid;
        }}
        h4 {{
            color: #666;
            margin-top: 15px;
            font-size: 14pt;
            page-break-after: avoid;
        }}
        code {{
            background: #f4f4f4;
            padding: 2px 6px;
            border-radius: 3px;
            font-family: 'Courier New', monospace;
            font-size: 10pt;
        }}
        pre {{
            background: #f6f8fa;
            padding: 16px;
            border-radius: 6px;
            overflow-x: auto;
            border: 1px solid #d1d5da;
            white-space: pre-wrap;
            word-wrap: break-word;
            page-break-inside: avoid;
        }}
        table {{
            border-collapse: collapse;
            width: 100%;
            margin: 20px 0;
            page-break-inside: avoid;
            font-size: 10pt;
        }}
        th, td {{
            border: 1px solid #ddd;
            padding: 8px 12px;
            text-align: left;
        }}
        th {{
            background-color: #f6f8fa;
            font-weight: 600;
        }}
        tr:nth-child(even) {{
            background-color: #f9f9f9;
        }}
        .mermaid {{
            background: white;
            padding: 20px;
            margin: 20px 0;
            border: 1px solid #e1e4e8;
            border-radius: 6px;
            page-break-inside: avoid;
            display: flex;
            justify-content: center;
        }}
        hr {{
            border: none;
            border-top: 1px solid #eee;
            margin: 30px 0;
        }}
        ul, ol {{
            margin: 10px 0;
            padding-left: 30px;
        }}
        li {{
            margin: 5px 0;
        }}
        strong {{
            font-weight: 600;
            color: #24292e;
        }}
        blockquote {{
            border-left: 4px solid #dfe2e5;
            padding-left: 16px;
            color: #6a737d;
            margin: 0 0 16px 0;
        }}
        a {{
            color: #0366d6;
            text-decoration: none;
        }}
        a:hover {{
            text-decoration: underline;
        }}
    </style>
</head>
<body>
{html_content}
</body>
</html>"""

    return html_template

def basic_markdown_to_html(md_text):
    """Basic markdown to HTML conversion (fallback)"""
    html = md_text

    # Headers
    html = re.sub(r'^#### (.*?)$', r'<h4>\1</h4>', html, flags=re.MULTILINE)
    html = re.sub(r'^### (.*?)$', r'<h3>\1</h3>', html, flags=re.MULTILINE)
    html = re.sub(r'^## (.*?)$', r'<h2>\1</h2>', html, flags=re.MULTILINE)
    html = re.sub(r'^# (.*?)$', r'<h1>\1</h1>', html, flags=re.MULTILINE)

    # Bold
    html = re.sub(r'\*\*(.*?)\*\*', r'<strong>\1</strong>', html)

    # Horizontal rule
    html = re.sub(r'^---$', r'<hr>', html, flags=re.MULTILINE)

    # Lists
    html = re.sub(r'^- (.*?)$', r'<li>\1</li>', html, flags=re.MULTILINE)

    # Paragraphs
    html = html.replace('\n\n', '</p><p>')

    return f'<p>{html}</p>'

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 md_to_pdf_with_mermaid.py <markdown_file>")
        print("Example: python3 md_to_pdf_with_mermaid.py Reference/Wheelchair_Navigation_Simple_Explanation.md")
        sys.exit(1)

    md_file = sys.argv[1]

    if not os.path.exists(md_file):
        print(f"Error: File not found: {md_file}")
        sys.exit(1)

    # Output files
    html_file = md_file.replace('.md', '_temp.html')
    pdf_file = md_file.replace('.md', '.pdf')

    print(f"Converting {md_file} to PDF...")
    print(f"Step 1: Creating HTML with Mermaid support...")

    # Convert to HTML
    html_content = convert_markdown_to_html_with_mermaid(md_file)

    # Write HTML file
    with open(html_file, 'w', encoding='utf-8') as f:
        f.write(html_content)

    print(f"  ✓ Created temporary HTML: {html_file}")

    print(f"Step 2: Rendering PDF with Chrome...")

    # Convert HTML to PDF using Chrome
    html_path = os.path.abspath(html_file)
    pdf_path = os.path.abspath(pdf_file)

    try:
        # Use Chrome headless to render PDF
        subprocess.run([
            'google-chrome',
            '--headless',
            '--disable-gpu',
            '--no-sandbox',
            '--print-to-pdf=' + pdf_path,
            '--no-pdf-header-footer',
            f'file://{html_path}'
        ], check=True, capture_output=True, timeout=30)

        # Wait a moment for file to be written
        import time
        time.sleep(2)

        if os.path.exists(pdf_file):
            print(f"  ✓ PDF created successfully: {pdf_file}")
            print(f"Step 3: Cleaning up...")
            os.remove(html_file)
            print(f"  ✓ Temporary HTML removed")
            print(f"\n✅ Done! Your PDF with Mermaid flowcharts is ready:")
            print(f"   {pdf_file}")
        else:
            print(f"  ✗ PDF file not created")
            print(f"  HTML file kept for debugging: {html_file}")
            sys.exit(1)

    except subprocess.TimeoutExpired:
        print("  ✗ Timeout while rendering PDF")
        print(f"  HTML file kept for debugging: {html_file}")
        sys.exit(1)
    except subprocess.CalledProcessError as e:
        print(f"  ✗ Error rendering PDF: {e}")
        print(f"  HTML file kept for debugging: {html_file}")
        sys.exit(1)
    except FileNotFoundError:
        print("  ✗ google-chrome not found")
        print("  Please install Google Chrome or Chromium")
        sys.exit(1)

if __name__ == '__main__':
    main()
