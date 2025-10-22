# BIM Script Explained - Learn Bash Scripting

This document explains how the `bim` alias works, breaking down each command and syntax so you can learn to create your own scripts.

## Table of Contents
1. [What is a Bash Alias?](#what-is-a-bash-alias)
2. [Script Structure](#script-structure)
3. [Command Explanations](#command-explanations)
4. [Useful Bash Concepts](#useful-bash-concepts)

---

## What is a Bash Alias?

An **alias** is a shortcut command in bash. Instead of typing a long command, you can create a short name for it.

### Basic Syntax:
```bash
alias name='command'
```

### Example:
```bash
alias ll='ls -la'
```
Now typing `ll` will run `ls -la` (list all files with details)

### Where to Store Aliases:
- **~/.bashrc** - This file runs every time you open a new terminal
- To reload after editing: `source ~/.bashrc`

---

## Script Structure

### The BIM Alias:
```bash
alias bim='(
    # Commands go here
)'
```

### Key Syntax Elements:

**1. Parentheses `( )`**
- Groups commands together in a subshell
- Keeps variables local to the script

**2. Single Quotes `' '`**
- Everything inside is treated as literal text
- Variables are NOT expanded (e.g., `$HOME` stays as `$HOME`)

**3. Double Quotes `" "`**
- Variables ARE expanded (e.g., `$HOME` becomes `/home/student`)
- Used when you need variable substitution

**4. Comments `#`**
- Lines starting with `#` are comments (ignored by bash)
- Use them to document your code

**5. Ampersand `&`**
- Runs command in the background
- Allows script to continue without waiting
- Example: `matlab &` starts MATLAB and continues immediately

---

## Command Explanations

### 1. Process Checking with `pgrep`

```bash
if ! pgrep -x "MATLAB" > /dev/null; then
    echo "Starting MATLAB..."
    matlab -sd "$PWD" &
else
    echo "MATLAB already running"
fi
```

**Breaking it down:**

- **`pgrep -x "MATLAB"`**
  - Searches for running processes matching "MATLAB"
  - `-x` = exact match only
  - Returns process ID if found, nothing if not found

- **`> /dev/null`**
  - Redirects output to nowhere (throws it away)
  - We only care if the command succeeds, not its output

- **`!`**
  - Negates the condition (means "NOT")
  - `if !` = "if NOT found"

- **`if ... then ... else ... fi`**
  - Standard bash if-statement structure
  - `fi` closes the if-statement (it's "if" backwards)

- **`$PWD`**
  - Built-in variable = Present Working Directory
  - Shows current directory path

- **`matlab -sd "$PWD"`**
  - `-sd` = start directory
  - Starts MATLAB in current folder

**Other useful pgrep options:**
```bash
pgrep -f "pattern"     # Search in full command line (not just process name)
pgrep -u username      # Search for user's processes only
pgrep -l "pattern"     # Show process name with PID
```

---

### 2. Docker Container Management

```bash
if ! docker ps | grep -q standing; then
    echo "Starting Docker container: standing..."
    docker start standing || echo "Failed to start"
    sleep 2
else
    echo "Container already running"
fi
```

**Breaking it down:**

- **`docker ps`**
  - Lists all running containers

- **`|` (pipe)**
  - Takes output from left command and feeds it to right command
  - `docker ps | grep` = "list containers, then search that list"

- **`grep -q standing`**
  - Searches for "standing" in the input
  - `-q` = quiet mode (no output, just success/fail)
  - Returns 0 if found, 1 if not found

- **`||` (OR operator)**
  - Runs second command only if first one fails
  - `docker start standing || echo "Failed"` = "try to start, if it fails, print error"

- **`sleep 2`**
  - Pauses for 2 seconds
  - Gives container time to fully start

**Other useful Docker commands:**
```bash
docker ps -a              # List all containers (including stopped)
docker exec -it NAME bash # Attach to running container
docker stop NAME          # Stop container
docker logs NAME          # View container logs
```

---

### 3. Running Commands in Docker

```bash
docker exec -it standing bash -c "source /opt/ros/melodic/setup.bash && ..."
```

**Breaking it down:**

- **`docker exec`**
  - Execute command in running container

- **`-it`**
  - `-i` = interactive (keep STDIN open)
  - `-t` = allocate pseudo-TTY (terminal)
  - Together = gives you an interactive terminal

- **`standing`**
  - Name of the container

- **`bash -c "commands"`**
  - Run bash with specific commands
  - `-c` = execute string of commands

- **`source /path/to/file`**
  - Executes script in current shell (loads environment variables)
  - Alternative: `. /path/to/file` (dot is shorthand for source)

- **`&&` (AND operator)**
  - Runs second command only if first succeeds
  - `cmd1 && cmd2 && cmd3` = chain of commands
  - If any fails, the rest don't run

**Example of command chaining:**
```bash
cd /tmp && mkdir test && cd test && touch file.txt
# Each command only runs if previous succeeded
```

---

### 4. Opening Terminal Windows

```bash
gnome-terminal --title="ROS Launch" --working-directory="/path" -- bash -c "commands"
```

**Breaking it down:**

- **`gnome-terminal`**
  - Opens a new terminal window (GNOME desktop environment)

- **`--title="Text"`**
  - Sets window title

- **`--working-directory="/path"`**
  - Sets starting directory for terminal

- **`--`**
  - Separates terminal options from the command to run
  - Everything after `--` is the command to execute

- **`bash -c "commands"`**
  - Runs commands in bash

- **`exec bash`**
  - Replaces current shell with new bash shell
  - Keeps terminal open after command finishes
  - Without this, terminal would close when command ends

**Example:**
```bash
gnome-terminal -- bash -c "ls -la && exec bash"
# Opens terminal, lists files, then stays open
```

---

### 5. Background Processes with `&`

```bash
matlab -sd "$PWD" &
code &
```

**Breaking it down:**

- **`&` at end of command**
  - Runs command in background
  - Shell continues to next command immediately
  - Parent shell doesn't wait for it to finish

**Without `&`:**
```bash
matlab        # Starts MATLAB, script waits until MATLAB closes
echo "Done"   # This won't print until you close MATLAB
```

**With `&`:**
```bash
matlab &      # Starts MATLAB in background
echo "Done"   # Prints immediately
```

**Managing background jobs:**
```bash
jobs          # List background jobs
fg            # Bring background job to foreground
bg            # Resume stopped job in background
kill %1       # Kill job number 1
```

---

### 6. Process Checking Variations

```bash
pgrep -f "2025NEDO従事日誌"              # Check for Excel file
docker exec standing pgrep -f "roslaunch" # Check inside container
```

**Breaking it down:**

- **`pgrep -f "pattern"`**
  - `-f` = search full command line (not just process name)
  - Useful for finding specific files or arguments

- **`> /dev/null 2>&1`**
  - `> /dev/null` = redirect stdout (standard output) to nowhere
  - `2>&1` = redirect stderr (error output) to same place as stdout
  - Silences all output

**Understanding output streams:**
```bash
command > file.txt        # Redirect stdout to file
command 2> errors.txt     # Redirect stderr to file
command > output.txt 2>&1 # Redirect both to same file
```

---

### 7. File Operations

```bash
xdg-open "/path/to/file.xlsx"
```

**Breaking it down:**

- **`xdg-open`**
  - Opens file with default application
  - Works for any file type (PDF, images, documents, etc.)
  - Linux equivalent of double-clicking a file

**Alternative commands:**
```bash
xdg-open file.pdf         # Open PDF with default viewer
xdg-open https://url.com  # Open URL in default browser
xdg-open .                # Open current folder in file manager
```

---

## Useful Bash Concepts

### Variables

**Defining variables:**
```bash
NAME="value"              # No spaces around =
MY_PATH="/home/student"   # Use quotes for paths with spaces
```

**Using variables:**
```bash
echo $NAME                # Print variable
echo ${NAME}              # Same, but clearer syntax
echo "$NAME"              # Expand inside quotes
```

**Special variables:**
```bash
$PWD         # Current directory
$HOME        # Home directory (/home/student)
$USER        # Username
$?           # Exit status of last command (0 = success)
$$           # Current shell process ID
$0           # Script name
$1, $2, ...  # Script arguments
```

---

### Conditional Statements

**Basic if statement:**
```bash
if [ condition ]; then
    commands
fi
```

**If-else:**
```bash
if [ condition ]; then
    commands
else
    other_commands
fi
```

**If-elif-else:**
```bash
if [ condition1 ]; then
    commands1
elif [ condition2 ]; then
    commands2
else
    commands3
fi
```

**Common conditions:**
```bash
[ -f file ]       # True if file exists
[ -d folder ]     # True if directory exists
[ -z "$VAR" ]     # True if variable is empty
[ "$A" = "$B" ]   # True if strings equal
[ $NUM -gt 5 ]    # True if number > 5
[ $NUM -lt 10 ]   # True if number < 10
[ $NUM -eq 5 ]    # True if number == 5
```

---

### Loops

**For loop:**
```bash
for item in item1 item2 item3; do
    echo $item
done
```

**For loop with range:**
```bash
for i in {1..5}; do
    echo "Number: $i"
done
```

**While loop:**
```bash
while [ condition ]; do
    commands
done
```

---

### Functions

**Defining a function:**
```bash
function my_function() {
    echo "Hello $1"
    return 0
}
```

**Calling a function:**
```bash
my_function "World"    # Prints: Hello World
```

---

### Useful Commands Reference

**File operations:**
```bash
ls              # List files
ls -la          # List all files with details
cd /path        # Change directory
pwd             # Print working directory
mkdir folder    # Create folder
rm file         # Remove file
rm -r folder    # Remove folder recursively
cp source dest  # Copy file
mv source dest  # Move/rename file
```

**Text processing:**
```bash
cat file        # Display file contents
head -n 10 file # Show first 10 lines
tail -n 10 file # Show last 10 lines
grep "text" file # Search for text in file
sed 's/old/new/g' file # Replace text
```

**Process management:**
```bash
ps aux          # List all processes
top             # Interactive process viewer
kill PID        # Kill process by ID
killall NAME    # Kill all processes by name
```

**System info:**
```bash
whoami          # Current username
hostname        # Computer name
date            # Current date/time
df -h           # Disk space
free -h         # Memory usage
```

---

## Creating Your Own Scripts

### Step 1: Create a script file
```bash
nano my_script.sh
```

### Step 2: Add shebang (first line)
```bash
#!/bin/bash
```

### Step 3: Write your commands
```bash
#!/bin/bash
echo "Hello, World!"
```

### Step 4: Make it executable
```bash
chmod +x my_script.sh
```

### Step 5: Run it
```bash
./my_script.sh
```

---

## Practice Exercises

**Exercise 1: Create a simple alias**
```bash
# Add to ~/.bashrc:
alias hello='echo "Hello, $(whoami)!"'
```

**Exercise 2: Check if a file exists before opening**
```bash
FILE="/path/to/file.txt"
if [ -f "$FILE" ]; then
    xdg-open "$FILE"
else
    echo "File not found!"
fi
```

**Exercise 3: Start multiple programs**
```bash
# Create a "start work" alias
alias startwork='(
    if ! pgrep -x "firefox" > /dev/null; then
        firefox &
    fi

    if ! pgrep -x "code" > /dev/null; then
        code &
    fi

    echo "Workspace ready!"
)'
```

---

## Debugging Tips

**Enable debug mode:**
```bash
set -x          # Print each command before executing
set +x          # Disable debug mode
```

**Check command syntax:**
```bash
bash -n script.sh    # Check for syntax errors without running
```

**Print variables for debugging:**
```bash
echo "Variable value: $VAR"
```

**Test parts of script:**
```bash
# Comment out parts with # to test specific sections
```

---

## Additional Resources

**Man pages (manual):**
```bash
man command     # Read manual for any command
man bash        # Bash manual
```

**Command help:**
```bash
command --help  # Quick help for command
```

**Online resources:**
- [Bash Guide for Beginners](https://tldp.org/LDP/Bash-Beginners-Guide/html/)
- [ShellCheck](https://www.shellcheck.net/) - Script validator
- [Explain Shell](https://explainshell.com/) - Break down commands

---

## Summary: The BIM Script Flow

1. ✅ Check if MATLAB is running → Start if not
2. ✅ Check if VS Code is running → Start if not
3. ✅ Check if Excel file is open → Open if not
4. ⏸️ Wait 3 seconds for apps to initialize
5. ✅ Check if Docker container "standing" is running → Start if not
6. ⏸️ Wait 2 seconds for container to be ready
7. ✅ Check if roslaunch is running in container → Start terminal if not
8. ⏸️ Wait 1 second
9. ✅ Check if Claude Code is running → Start terminal if not
10. ✅ Print completion message

Each step prevents duplicate processes while ensuring everything you need is running!

---

**Created for learning bash scripting - Muhammad Haziq**
*Last updated: 2025-10-09*
