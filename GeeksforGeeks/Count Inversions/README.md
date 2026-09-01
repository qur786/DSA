# Count Inversions

**Difficulty:** Medium

## Description

<p><span style="font-size: 14pt;">Given an array of integers <strong>arr[]</strong>. You have to find the<strong> </strong>Inversion Count of the array. I</span><span style="font-size: 14pt;">nversion count is the number of pairs of elements (i, j) such that i &lt; j and arr[i] &gt; arr[j].</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: arr[] = [2, 4, 1, 3, 5]<br /><strong>Output</strong>: 3
<strong>Explanation</strong>: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: arr[] = [2, 3, 4, 5, 6]<br /><strong>Output</strong>: 0
<strong>Explanation</strong>: As the sequence is already sorted so there is no inversion count.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: arr[] = [10, 10, 10]<br /><strong>Output</strong>: 0
<strong>Explanation</strong>: As all the elements of array are same, so there is no inversion count.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong></span><br /><span style="font-size: 14pt;">1 &le; arr.size()</span><span style="font-size: 14pt;">&nbsp;&le; 10</span><sup>5<br /></sup><span style="font-size: 14pt;">1 &le; </span><span style="font-size: 18.6667px;">arr[i]</span><span style="font-size: 14pt;"> &le; 10</span><sup>4</sup><sup><br /></sup></p>