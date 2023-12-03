# plot_script.gnu
set terminal png
set output 'plot.png'

set title 'Execution Time vs Input Size'
set xlabel 'Input Size'
set ylabel 'Execution Time (seconds)'

# Use dots for points
set style data points

# Plot the data from the file
plot 'BubbleSortBenchmark' with linespoints title 'BubbleSort', \
     'CountingSortBenchmark' with linespoints title 'CountingSort', \
     'InsertionSortBenchmark' with linespoints title 'InsertionSort', \
     'SelectionSortBenchmark' with linespoints title 'SelectionSort', \
     'SelectionMinMaxSortBenchmark' with linespoints title 'SelectionMinMaxSort', \