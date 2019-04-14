# Best-Approach

![1553962446302](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\1553962446302.png)

Since the *PersonId* in table **Address** is the foreign key of table **Person**, we can join this two table to get the address information of a person.

Considering there might not be an address information for every person, we should use `outer join` instead of the default `inner join`.