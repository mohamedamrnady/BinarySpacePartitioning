# Binary Space Partitioning (BSP) Project

## Overview

The Binary Space Partitioning (BSP) project is a C++ implementation of a spatial data structure that recursively subdivides 2D space into convex regions. This implementation provides efficient point location queries and spatial organization through a binary tree structure, where each node represents a partition plane that divides space into two half-spaces.

## Project Description

Binary Space Partitioning is a fundamental technique in computational geometry used extensively in computer graphics, collision detection, and spatial databases. This project demonstrates the construction, querying, and visualization of BSP trees for organizing 2D point sets.

### Key Features

- **Recursive Tree Construction**: Builds BSP trees using axis-aligned median splitting strategy
- **Efficient Point Location**: Quickly determines which spatial partition contains a query point
- **Tree Analysis Tools**: Provides statistics including depth, node count, and leaf distribution
- **ASCII Visualization**: Generates text-based visualization of the tree structure and spatial partitions
- **Configurable Parameters**: Customizable maximum depth and splitting thresholds
- **File-Based Input**: Reads point datasets from text files
- **Comprehensive Testing**: Includes multiple test cases demonstrating various scenarios

## Architecture

### Core Components

#### Data Structures

**Point** (`Point.h`, `Point.cpp`)

- Represents 2D coordinates (x, y)
- Provides basic point operations and printing functionality

**BSPNode** (`BSPNode.h`, `BSPNode.cpp`)

- Represents a node in the BSP tree
- Stores partition line coefficients (a, b, c) for equation: ax + by + c = 0
- Contains pointers to left and right child nodes
- Maintains point list for leaf nodes
- Includes leaf node identification flag

#### Modules

**BSP Core** (`bsp_core.h`, `bsp_core.cpp`)

- `buildBSPTree()`: Constructs BSP tree from point collection
- `choosePartition()`: Selects optimal partition line using alternating axis strategy
- `isLeftOf()`: Determines point position relative to partition line
- `splitPoints()`: Distributes points into left and right subsets

**BSP Query** (`bsp_query.h`, `bsp_query.cpp`)

- `findPartition()`: Locates the leaf node containing a query point
- `countNodes()`: Calculates total number of nodes in tree
- `countLeaves()`: Counts leaf nodes in tree
- `getTreeDepth()`: Determines maximum depth of tree
- `printTree()`: Displays tree structure in hierarchical format
- `verifyAllPoints()`: Validates that all points are properly contained

**BSP Visualize** (`bsp_visualize.h`, `bsp_visualize.cpp`)

- `visualizeASCII()`: Generates ASCII art representation of spatial partitions
- Displays point distribution across partitioned space

**Input Parser** (`input_parser.h`, `input_parser.cpp`)

- `readPointsFromFile()`: Reads point datasets from text files
- Supports simple text format with point count followed by coordinate pairs

## Algorithm Details

### Partition Strategy

The implementation uses an axis-aligned median splitting strategy:

1. **Alternating Axes**: Even depths split on X-axis, odd depths split on Y-axis
2. **Median Selection**: Chooses median coordinate value as partition location
3. **Balanced Subdivision**: Aims to distribute points evenly between subtrees

### Point Classification

Points are classified relative to partition lines using the equation:

```
ax + by + c = 0
```

- **Left Side**: Points where `ax + by + c ≤ 0`
- **Right Side**: Points where `ax + by + c > 0`

For axis-aligned partitions:

- **Vertical line** (x = k): a=1, b=0, c=-k
- **Horizontal line** (y = k): a=0, b=1, c=-k

### Termination Conditions

Tree construction stops when:

- Maximum depth is reached (default: 10)
- Point count falls below threshold (default: 3)
- Region contains insufficient points to subdivide

## Building the Project

### Prerequisites

- CMake 3.10 or higher
- C++11 compliant compiler:
  - GCC (Linux/macOS)
  - MSVC (Windows)
  - Clang

### Build Instructions

#### Linux/macOS

```bash
mkdir build
cd build
cmake ..
make
```

#### Windows

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### Configuration Options

The CMake configuration includes:

- C++11 standard enforcement
- Warning flags for code quality (`-Wall -Wextra -pedantic` for GCC, `/W4` for MSVC)
- Automatic test data copying to build directory
- Installation targets for deployment

## Usage

### Basic Execution

```bash
./bsp_project <input_file>
```

### Input File Format

Input files should follow this structure:

```
<number_of_points>
<x1> <y1>
<x2> <y2>
...
<xn> <yn>
```

Example (`test_case_1.txt`):

```
4
0.0 0.0
10.0 0.0
0.0 10.0
10.0 10.0
```

### Running Test Cases

Execute all provided test cases:

```bash
make test_all
```

Or run individually:

```bash
./bsp_project data/test_case_1.txt
./bsp_project data/test_case_2.txt
./bsp_project data/test_case_3.txt
```

## Output

The program provides comprehensive output including:

1. **Input Confirmation**: Number of points read from file
2. **Tree Statistics**:
   - Maximum depth achieved
   - Total node count
   - Leaf node count
3. **Tree Structure**: Hierarchical display of partition tree
4. **ASCII Visualization**: Text-based spatial partition diagram
5. **Query Demonstration**: Sample point location query results

## Test Cases

The project includes three test cases demonstrating different scenarios:

- **Test Case 1**: Simple 4-point square configuration
- **Test Case 2**: More complex point distribution
- **Test Case 3**: Larger dataset for deeper tree construction

## Installation

```bash
make install
```

Default installation locations:

- Executable: `<prefix>/bin/bsp_project`
- Data files: `<prefix>/share/bsp_project/data/`

## Project Structure

```
BinarySpacePartitioning/
├── CMakeLists.txt          # Build configuration
├── README.md               # This file
├── CODE_DOCUMENTATION.md   # Detailed code documentation
├── include/                # Header files
│   ├── BSPNode.h
│   ├── Point.h
│   ├── bsp_core.h
│   ├── bsp_query.h
│   ├── bsp_visualize.h
│   └── input_parser.h
├── src/                    # Implementation files
│   ├── BSPNode.cpp
│   ├── Point.cpp
│   ├── bsp_core.cpp
│   ├── bsp_query.cpp
│   ├── bsp_visualize.cpp
│   ├── input_parser.cpp
│   └── main.cpp
├── data/                   # Test datasets
│   ├── test_case_1.txt
│   ├── test_case_2.txt
│   └── test_case_3.txt
└── build/                  # Build directory (generated)
```

## Performance Characteristics

### Time Complexity

- **Tree Construction**: O(n log n) average case for balanced trees
- **Point Query**: O(log n) for balanced trees, O(n) worst case
- **Tree Traversal**: O(n) for full tree traversal operations

### Space Complexity

- **Tree Storage**: O(n) where n is the number of points
- **Each Node**: Constant space for partition coefficients and pointers

## Applications

BSP trees are widely used in:

- **Computer Graphics**: Scene rendering and visibility determination
- **Game Development**: Collision detection and spatial partitioning
- **Robotics**: Motion planning and obstacle avoidance
- **Geographic Information Systems**: Spatial indexing and range queries
- **Computational Geometry**: Point location and region queries