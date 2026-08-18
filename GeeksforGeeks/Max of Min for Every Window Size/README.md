# Max of Min for Every Window Size

**Difficulty:** Hard

## Description

<p><span style="font-size: 14pt;">Given an integer array <strong>arr[]</strong>, <span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">find the </span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">maximum of minimum values</span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"> for every window size <strong>k</strong> </span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">where&nbsp;</span><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;">1&le; k &le; arr.size().</span></span></p>
<p data-start="416" data-end="592"><span style="font-size: 14pt;">For each window size<strong> </strong>k, consider all contiguous subarrays of length k, determine the minimum element in each subarray, and then take the maximum among all these minimums.</span></p>
<p data-start="416" data-end="592"><span style="font-size: 14pt;">Return the results as an array, where the element at index&nbsp;<strong>i</strong> represents the answer for window size<strong> </strong>i+1.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [10, 20, 30, 50, 10, 70, 30]
<strong>Output: </strong>[70, 30, 20, 10, 10, 10, 10] <strong>
Explanation: <br /></strong>Window size 1: minimums are [10, 20, 30, 50, 10, 70, 30], maximum of minimums is 70.<br />Window size 2: minimums are [10, 20, 30, 10, 10, 30], maximum of minimums is 30.<br />Window size 3: minimums are [10, 20, 10, 10, 10], maximum of minimums is 20.<br />Window size 4&ndash;7: minimums are [10, 10, 10, 10], maximum of minimums is 10.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [10, 20, 30]
<strong>Output: </strong>[30, 20, 10]<strong>
Explanation: <br /></strong>Window size 1: minimums of  [10], [20], [30], maximum of minimums is 30.<br />Window size 2: minimums of [10, 20], [20,30], maximum of minimums is 20.<br /></span><span style="font-size: 14pt;">Window size 3: minimums of [10,20,30], maximum of minimums is 10.</span></pre>