<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<HTML><HEAD>
<META http-equiv=Content-Type content="text/html; charset=windows-1252"></HEAD>
<BODY><PRE>#!/usr/bin/python
# Integer unbiaser version 1.0

# Convert a biased uncorrelated stream of integers (eg, click
# intervals from a Geiger counter) into an unbiased uncorrelated
# bitstream.  See
   
# http://www.ciphergoth.org/software/unbiasing

import random

def amls(stream):
    if len(stream) &lt; 2:
        return []
    res = []
    s1 = []
    sa = []
    p0 = None
    for p1 in stream:
        if p0 == None:
            p0 = p1
        else:
            if p0 == p1:
                sa.append(0)
                s1.append(p0)
            else:
                sa.append(1)
                res.append(p0)
            p0 = None
    return res + amls(sa) + amls(s1)

def extract_juice(data):
    if len(data) &lt; 3:
        return []
    pivot = data[0]
    data[0:1] = []
    nonp = [x for x in data if x != pivot]
    if len(nonp) == 0:
        return []
    bits = amls([x == pivot for x in data]) + amls([x &lt; pivot for x in nonp])
    left = [x for x in nonp if x &lt; pivot]
    right = [x for x in nonp if x &gt; pivot]
    return (bits + extract_juice(left) + extract_juice(right))

n = 1
k = 1024
for i in range(0, n):
    # Numbers from HotBits hbhist.gif
    data = []
    for j in range(0, k):
        sample = int(0.5 + random.gauss(1889.35,26.4))
        #sample = (sample * 1000) % 2011
        data.append(sample)
    bits = len(extract_juice(data))
    print "Bits:", bits
    print "Efficiency: ", bits * 1.0 / k

# Copyright (C) 2002 Paul Crowley &lt;paul@ciphergoth.org&gt;
# November 2002

# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation files
# (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge,
# publish, distribute, sublicense, and/or sell copies of the Software,
# and to permit persons to whom the Software is furnished to do so,
# subject to the following conditions:

# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
# BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
# ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
</PRE></BODY></HTML>
