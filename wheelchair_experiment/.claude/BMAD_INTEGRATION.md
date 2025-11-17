# BMAD-METHOD Integration Guide

## What is BMAD-METHOD?
BMAD-METHOD is a universal human-AI collaboration platform with specialized agents for agile development, system design, and project management.

## Installation Location
- **Installed at**: `/home/student/Document/HaziqTest/bim_ros2/.bmad/`
- **Linked to project**: Symbolic link at `.bmad/` (in wheelchair_experiment)

## Available Agents (via Slash Commands)

### Core BMM Agents
Use these slash commands in Claude Code to load specialized agents:

- **`/bmad-pm`** - Product Manager
  - Create PRDs (Product Requirements Documents)
  - Define epics and user stories
  - Workflow initialization and status tracking
  - Commands: `*workflow-init`, `*create-prd`, `*workflow-status`

- **`/bmad-architect`** - Software Architect
  - System architecture design
  - Technical specifications
  - Architecture validation
  - Commands: `*tech-spec`, `*validate-tech-spec`

- **`/bmad-dev`** - Developer
  - Implementation guidance
  - Code development
  - Technical problem-solving

- **`/bmad-analyst`** - Business Analyst
  - Requirements analysis
  - User research
  - Data-driven insights

- **`/bmad-sm`** - Scrum Master
  - Sprint planning
  - Agile ceremonies
  - Team coordination

- **`/bmad-ux`** - UX Designer
  - User experience design
  - Interface design
  - Usability analysis

## How to Use

### 1. Start a Workflow (Recommended First Step)
```
/bmad-pm
```
Then when the PM agent loads, type:
```
*workflow-init
```
This initializes the project workflow and guides you through the planning process.

### 2. Check Workflow Status
```
/bmad-pm
*workflow-status
```

### 3. Create Planning Documents
```
/bmad-pm
*create-prd
```
Or for technical specs:
```
/bmad-architect
*tech-spec
```

### 4. Get Help from Any Agent
After loading an agent with `/bmad-xxx`, type:
```
*help
```
This shows all available commands for that agent.

## Agent Workflow Commands

Each agent has built-in workflow commands (triggered with `*` prefix):

### Common Commands (Most Agents)
- `*help` - Show agent's menu and capabilities
- `*exit` - Exit the agent

### PM Agent Commands
- `*workflow-init` - Start new workflow (START HERE!)
- `*workflow-status` - Check progress
- `*create-prd` - Create Product Requirements Document
- `*create-epics-and-stories` - Break PRD into implementable tasks
- `*validate-prd` - Validate PRD completeness
- `*correct-course` - Course correction analysis
- `*party-mode` - Consult multiple agents

### Architect Agent Commands
- `*tech-spec` - Create Technical Specification
- `*validate-tech-spec` - Validate tech spec
- `*architecture-review` - Review system design

## Configuration

The BMAD installation is configured with:
- **User Name**: Joe (configured during installation)
- **Communication Language**: English
- **Output Language**: English
- **Output Folder**: `{project-root}/docs`

You can modify these settings in:
```
.bmad/core/config.yaml
.bmad/bmm/config.yaml
```

## Custom Workflows

BMAD workflows are located at:
- Core workflows: `.bmad/core/workflows/`
- BMM workflows: `.bmad/bmm/workflows/`

Workflow structure:
- `1-analysis-workflows/` - Discovery and analysis
- `2-plan-workflows/` - Planning (PRD, Tech Spec, UX Design)
- `3-solution-workflows/` - Solution design
- `4-implementation/` - Implementation tracking

## Tips for Wheelchair Navigation Project

### For Multi-Room Navigation Implementation
1. Use `/bmad-pm` → `*workflow-init` to plan the feature
2. Use `/bmad-architect` → `*tech-spec` for technical design
3. Use `/bmad-dev` for implementation guidance

### For Bounding Box FPM Implementation
1. Use `/bmad-architect` to design the algorithm architecture
2. Use `/bmad-pm` → `*create-epics-and-stories` to break down tasks
3. Use `/bmad-dev` for coding assistance

### For Bug Fixes (like PhaseManager redundancy)
1. Use `/bmad-architect` to analyze the architecture issue
2. Use `/bmad-dev` for refactoring guidance

## Troubleshooting

### If slash commands don't work:
1. Restart Claude Code
2. Check that `.bmad` symbolic link exists: `ls -la .bmad`
3. Verify commands exist: `ls .claude/commands/bmad-*.md`

### If workflows fail to load:
1. Check that all files exist in `.bmad/bmm/workflows/`
2. Verify config files: `.bmad/core/config.yaml` and `.bmad/bmm/config.yaml`

### If you need to reinstall:
1. Delete symbolic link: `rm .bmad`
2. Go to bim_ros2 and run: `npx bmad-method@alpha install`
3. Recreate symbolic link: `ln -s ~/Document/HaziqTest/bim_ros2/.bmad .bmad`

## Git Configuration

The `.bmad/` directory is excluded from git commits (added to `.gitignore`). This is because:
- It's a symbolic link to an external installation
- BMAD updates should be managed separately
- Keeps the repository clean

---

**Quick Start Command:**
```
/bmad-pm
*workflow-init
```

This will guide you through the entire project setup process!
