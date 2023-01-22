For this case I took an bit-array of 50 bits and added 10 elements to it. to get the most out of the filter, I’ll need (m/n)ln2 hash functions, which in this case would be equal to around 3 hash functions.
With the formula for probabilities of false positives, this would give us (1 – e^(-kn/m))^k = 0.0918 = 9% chance.

You can change the size of the "bitarray" to your liking, same with the elements.

I used catch to make a simple testcase for some usernames. If you run it, you'll see there will be two fails, which are two false positives.

The includes hold the headers, the src hold de .cpp files, test holds the test cases with catch
