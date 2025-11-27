# BSP Tree Project

Binary Space Partitioning implementation in C++ for data structures course.

## Project Overview

This project implements a Binary Space Partitioning (BSP) tree data structure for organizing 2D points. The BSP tree recursively divides space using axis-aligned partition lines, enabling efficient spatial queries and organization.

## Team Structure

This is a collaborative project with 5 team members, each responsible for a specific module:

- **Person 1: Core BSP Algorithm** (`src/bsp_core.cpp`)
  - Implements tree construction
  - Partition line selection strategy
  - Point splitting logic

- **Person 2: Input Parser** (`src/input_parser.cpp`)
  - File I/O operations
  - Input validation
  - Random point generation

- **Person 3: Query & Traversal** (`src/bsp_query.cpp`)
  - Tree traversal algorithms
  - Point location queries
  - Tree statistics

- **Person 4: Visualization** (`src/bsp_visualize.cpp`)
  - ASCII visualization
  - Partition line display

- **Person 5: Integration & Main** (`src/main.cpp`)
  - Overall integration
  - Testing coordination
  - Additional features

## Build Instructions

This project uses CMake for cross-platform compilation and works with GCC on both Linux and Windows.

### Prerequisites

- CMake 3.10 or higher
- GCC (MinGW-w64 on Windows, or system GCC on Linux)
- C++11 compatible compiler

### Building on Linux

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build the project
cmake --build .

# Or use make directly
make
```

### Building on Windows (with MinGW/GCC)

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake (specify MinGW generator)
cmake .. -G "MinGW Makefiles"

# Build the project
cmake --build .

# Or use mingw32-make
mingw32-make
```

### Clean Build

```bash
# Remove build directory and start fresh
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
```

## Running the Program

After building, run the executable with a test case file:

```bash
# From the build directory
./bsp_project data/test_case_1.txt

# On Windows
bsp_project.exe data\test_case_1.txt
```

## Testing

Run all test cases at once:

```bash
# From the build directory
cmake --build . --target test_all

# Or with make
make test_all
```

Individual test cases:
```bash
./bsp_project data/test_case_1.txt
./bsp_project data/test_case_2.txt
./bsp_project data/test_case_3.txt
```

## Project Structure

```
bsp-project/
├── CMakeLists.txt          # Build configuration
├── README.md               # This file
├── .gitignore             # Git ignore rules
├── include/               # Header files
│   ├── Point.h           # 2D point structure
│   ├── BSPNode.h         # BSP tree node structure
│   ├── bsp_core.h        # Core BSP algorithms
│   ├── input_parser.h    # Input/output functions
│   ├── bsp_query.h       # Query and traversal
│   └── bsp_visualize.h   # Visualization functions
├── src/                  # Implementation files
│   ├── Point.cpp         # Point implementation
│   ├── BSPNode.cpp       # BSPNode implementation
│   ├── bsp_core.cpp      # Core algorithms (STUBS)
│   ├── input_parser.cpp  # I/O implementation (STUBS)
│   ├── bsp_query.cpp     # Query implementation (STUBS)
│   ├── bsp_visualize.cpp # Visualization (STUBS)
│   └── main.cpp          # Main program
├── data/                 # Test data files
│   ├── test_case_1.txt  # 4 points (2x2 grid)
│   ├── test_case_2.txt  # 10 random points
│   └── test_case_3.txt  # 2 duplicate points
└── build/                # Build output (created by CMake)
```

## Input File Format

Test case files follow this format:

```
N
x1 y1
x2 y2
...
xN yN
```

Where:
- Line 1: `N` = number of points
- Lines 2 to N+1: Space-separated x and y coordinates (doubles)

Example (`test_case_1.txt`):
```
4
0.0 0.0
10.0 0.0
0.0 10.0
10.0 10.0
```

## Implementation Status

### Complete Implementations
- ✅ `Point` struct (include/Point.h, src/Point.cpp)
- ✅ `BSPNode` struct (include/BSPNode.h, src/BSPNode.cpp)
- ✅ `main.cpp` - Integration and testing harness

### Stub Implementations (TODO)
- ⚠️ `bsp_core.cpp` - Core BSP tree building algorithms
- ⚠️ `input_parser.cpp` - File I/O and validation
- ⚠️ `bsp_query.cpp` - Tree queries and statistics
- ⚠️ `bsp_visualize.cpp` - Visualization functions

## Development Guide

### Important Conventions

#### Partition Line Format
Partition lines follow the equation: `ax + by + c = 0`

- **Vertical line** (x = k): `a=1, b=0, c=-k`
- **Horizontal line** (y = k): `a=0, b=1, c=-k`

#### Point Classification
Points are classified relative to a partition line:
- Point `(x,y)` is **"left"** if `ax + by + c <= 0`
- Point `(x,y)` is **"right"** if `ax + by + c > 0`
- Points **on the line** go to the **LEFT** subtree (important!)

#### Tree Building Strategy
- **Alternating splits**: Even depth = split on X axis, odd depth = split on Y axis
- **Median-based**: Use median coordinate value for split position
- **Stopping criteria**: Create leaf when `points <= threshold` OR `depth >= maxDepth`
- **Default parameters**: `threshold = 3`, `maxDepth = 10`

### Next Steps for Each Team Member

#### Person 1: BSP Core (`bsp_core.cpp`)

Implement the following functions:

1. **`buildBSPTree()`** - Main recursive tree builder
   - Check stopping criteria (depth, point count)
   - Choose partition line using `choosePartition()`
   - Split points using `splitPoints()`
   - Recursively build left and right subtrees
   - Return root node

2. **`choosePartition()`** - Partition line selection
   - Determine axis based on depth (even = X, odd = Y)
   - Find median coordinate value
   - Set a, b, c coefficients for axis-aligned line

3. **`splitPoints()`** - Split points based on partition
   - Use `isLeftOf()` to classify each point
   - Add to leftPoints or rightPoints accordingly
   - Handle edge case: points exactly on line go left

**Test with**: `data/test_case_1.txt` (should create depth-2 tree with 4 leaves)

#### Person 2: Input Parser (`input_parser.cpp`)

Implement the following functions:

1. **`readPointsFromFile()`** - Parse input file
   - Open file and check for errors
   - Read N (number of points)
   - Read N lines of x,y coordinates
   - Create Point objects and add to vector
   - Handle file format errors gracefully

2. **`validatePoints()`** - Validate input
   - Check vector is not empty
   - Verify coordinates are valid (not NaN, not Inf)
   - Check for reasonable range (optional)
   - Return true/false

3. **`generateRandomPoints()`** - Create test data
   - Initialize random seed
   - Generate count random points in specified range
   - Return vector of Points

**Test with**: All three test case files, verify correct parsing

#### Person 3: Query (`bsp_query.cpp`)

Implement the following functions:

1. **`findPartition()`** - Locate point in tree
   - Base case: return nullptr if root is null
   - Base case: return root if it's a leaf
   - Use `isLeftOf()` to determine which child to recurse into
   - Recursively search appropriate subtree

2. **`countNodes()`** - Count all nodes
   - Base case: 0 if nullptr
   - Recursive case: 1 + countNodes(left) + countNodes(right)

3. **`countLeaves()`** - Count leaf nodes only
   - Base case: 0 if nullptr
   - Base case: 1 if root->isLeaf
   - Recursive case: countLeaves(left) + countLeaves(right)

4. **`getTreeDepth()`** - Find maximum depth
   - Base case: 0 if nullptr
   - Recursive case: 1 + max(getTreeDepth(left), getTreeDepth(right))

5. **`printTree()`** - Display tree structure
   - Print with indentation based on depth
   - Show partition line for internal nodes
   - Show point count for leaf nodes
   - Recursively print children

6. **`verifyAllPoints()`** - Verify completeness
   - For each input point, use findPartition() to locate it
   - Return false if any point not found
   - Return true if all found

**Test with**: Queries on test case 1 points, verify statistics

#### Person 4: Visualization (`bsp_visualize.cpp`)

Implement the following functions:

1. **`visualizeASCII()`** - Draw ASCII grid
   - Find bounding box of all points (min/max x/y)
   - Create gridSize x gridSize character grid
   - Draw partition lines as '-' (horizontal) or '|' (vertical)
   - Draw points as '*' or 'o'
   - Print the grid row by row

2. **`printPartitionLines()`** - List partition lines
   - Traverse tree (any order)
   - For internal nodes, print partition equation
   - Convert to readable format:
     - Vertical: "x = value"
     - Horizontal: "y = value"
   - Show both equation and readable form

**Test with**: `data/test_case_1.txt` (should show clear 2x2 grid)

#### Person 5: Integration (`main.cpp`)

- Monitor that all modules work together correctly
- Enhance `main.cpp` with additional features:
  - Interactive mode for queries
  - Performance timing
  - Additional statistics
- Create more complex test cases if needed
- Document any integration issues
- Coordinate final testing and presentation

## Testing Your Module

Each person should follow these steps:

1. **Make changes** to your assigned .cpp file
2. **Build**: `cd build && cmake --build .`
3. **Run tests**: `./bsp_project data/test_case_1.txt`
4. **Verify output**: Check that your module's functionality works
5. **Document issues**: Add comments for any problems encountered

## Timeline Suggestion

- **Days 1-3**: Everyone reviews codebase, understands interfaces, sets up build environment
- **Days 4-9**: Parallel implementation of modules (each person works independently)
- **Day 10**: Integration testing, fix interface mismatches
- **Days 11-14**: Polish, additional testing, presentation preparation

## Troubleshooting

### Build Issues

**"Cannot find header files"**
- Ensure you're running CMake from the project root directory
- Check that include/ directory exists and contains all .h files

**"Undefined reference" errors**
- Make sure all .cpp files are listed in CMakeLists.txt
- Verify function signatures match between .h and .cpp files

**GCC not found on Windows**
- Install MinGW-w64 or TDM-GCC
- Add GCC bin directory to system PATH
- Specify generator: `cmake .. -G "MinGW Makefiles"`

### Runtime Issues

**"Could not open file"**
- Ensure you're running from build/ directory
- Use correct path: `data/test_case_1.txt`
- Check that data files were copied to build/data/

**Segmentation fault**
- Check for null pointer dereferences
- Verify memory management in BSPNode destructor
- Use debugger: `gdb ./bsp_project`

## Contributing

When working on your module:
1. Only modify your assigned .cpp file
2. Do not change header files without team discussion
3. Follow existing code style and conventions
4. Add comments explaining your implementation
5. Test thoroughly before committing

## Additional Resources

- [BSP Trees Wikipedia](https://en.wikipedia.org/wiki/Binary_space_partitioning)
- [CMake Documentation](https://cmake.org/documentation/)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)

## License

This project is for educational purposes as part of a data structures course.
