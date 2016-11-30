Project 05: Path Finding
========================

This [project] implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[project]:              https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project05.html
[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]


Changes to output.txt
---------------------

Dijkstra's results for input0.txt and input3.txt were the same as output0.txt and output3.txt

In output1

Original: 5 5, 11 10

Cost: 5 5 = g

11 10 = G

Total cost = 1 + 2 = 3

Alternative: 6 4, 12 9

Cost: 6 4 = g

12 9 = G

Total cost = 1 + 2 = 3



In output2

Original: 2 2, 2 3

Cost: 2 2 = r

2 3 = g

Total cost = 5 + 1 = 6

Alternative: 3 1, 3 2

Cost: 3 1 = h

3 2 = G

Total cost = 4 + 2 = 6


Questions
---------

2.

| N    | Elapsed Time (s) | Memory Usage (Mb) |
|------|------------------|-------------------|
| 10   | 0.004            | 1.19              |
| 20   | 0.006            | 1.23              |
| 50   | 0.03             | 1.46              |
| 100  | 0.12             | 2.33              |
| 200  | 0.54             | 5.78              |
| 500  | 3.96             | 29.85             |
| 1000 | 17.70            | 115.76            |

3. The map is stored as a 2D array of strings called 'tile_grid'. The different tiles and their weights are stored as a map named 'tiles'.

So when we want to determine the cost of going over to the next index (ie. going left/right/up/down), we can do tiles[ tile_grid[i][j] ].

The complexity is O(E logV). We use a priority queue to represent the frontier, so pushing to frontier takes complexity of O(log V). We push to frontier E times, so the complexity of the entire algorithm is O(E logV).

As N increases, elapsed time and memory usage increase almost exponentially. The biggest difference can be seen between N=500 and N=1000, where elapsed time increased by a factor of 4.5 and memory usage, by 3.8, approximately. 

Douglas (dschmied) did the Dijkstra algorithm. Emily (epark3) and Andrew (apaek1) did the README.
