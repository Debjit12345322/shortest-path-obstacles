# Shortest Path Amid Polygonal Obstacles

This project is about finding the **shortest path between two points in a 2D plane** when there are **polygonal obstacles** in between.

The main idea is to avoid obstacles while still taking the shortest possible route.  
This is a classic problem in **computational geometry** and **robot motion planning**.

I solved it using a **visibility graph** and **Dijkstra’s algorithm**, and also added a simple **visualization** to see the path clearly.

---

## Problem Description

Given:
- A start point
- An end point
- Multiple polygonal obstacles (non-overlapping)

The task is to compute the **shortest collision-free path** from start to end.  
The path must not pass through any obstacle, but it is allowed to touch obstacle vertices or edges.

---

## How the Solution Works

### 1. Geometry Basics
First, I implemented basic geometric operations:
- Checking orientation of points
- Detecting line segment intersections
- Computing Euclidean distance

These are used to check whether two points are **visible** to each other.

---

### 2. Visibility Graph
I create a graph where:
- Nodes are the start point, end point, and all obstacle vertices
- An edge exists between two nodes if the straight line joining them does **not intersect any obstacle**

Each edge weight is simply the Euclidean distance between the two points.

---

### 3. Shortest Path
Once the visibility graph is built, I run **Dijkstra’s algorithm** to find the shortest path from the start node to the end node.

The final path is obtained by backtracking using parent pointers.

---

### 4. Visualization
To better understand and verify the result, I added a Python visualization:
- Obstacles are drawn as black polygons
- Start and end points are shown in blue
- The shortest path is drawn in red

---

## Time Complexity

Let n be the total number of obstacle vertices.

- Visibility checking is done in O(n)
- Graph construction takes O(n²)
- Dijkstra runs in O(E log V)

Overall complexity is approximately:

O(n² log n)

## Input Format

(sx sy)
(tx ty)
(M)
(k1)
(x11 y11)
...
(x1k1 y1k1)
(k2)
...
(kM)

- (sx, sy) → start point  
- (tx, ty) → end point  
- M → number of obstacles  
- ki → number of vertices in obstacle i  
- Vertices are given in counter-clockwise order

---

## Output Format

L
(x1 y1)
(x2 y2)
...
(xL yL)

Where L is the number of points in the shortest path.

---

## Example

**Input**
0 0
10 10
2
4
2 2
4 2
4 4
2 4
3
6 6
8 6
7 8


**Output**
5
0 0
2 2
4 4
7 8
10 10
