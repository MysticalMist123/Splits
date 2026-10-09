Hi,

So this is a simplified version of Splitwise in cpp. Just made it, so not sure how reliable it is, but I felt this could still be useful

In transactions.txt, Fill each row as "borrower lender amount" with comma between them to note down the transactions. (You can refer to the example already provided with it)

To create the executable binary, just type make in the command line. If you don't have make, just use the below command:

g++ splits.cpp -o splits

To remove the binary (let's say in case you want to rebuild it), then use make clean command. Or just remove the splits binary.
