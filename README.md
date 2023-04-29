This code sets up the challenge, and acts as both parties in the following puzzle: https://www.cantorsparadise.com/a-fascinating-prisoners-puzzle-be874032f43e

We use clever xor math to write short code that simulates and solves the game quickly.
The solution is to have the state of the board represent where the key is by xor'ing all the squares (0...63) where the coin is heads. 
Then, prisoner 1 can flip over the exact coin to reconfigure the board to wherever he wants to point prisoner 2 too. This is deterministically true because whatever xor mask you wish to apply is definitely available (This is not the case if the chess board is not a perfect power of 2)
