What are Vectors in C++?
-----


Vectors are part of STL. Vectors in C++ are sequence containers representing arrays that can change their size during runtime. They use contiguous storage locations for their elements just as efficiently as in arrays, which means that their elements can also be accessed using offsets on regular pointers to its elements.

Vectors are the dynamic arrays that are used to store data.It is different from arrays which store sequential data and are static in nature, Vectors provide more flexibility to the program. Vectors can adjust their size automatically when an element is inserted or deleted from it.

Vectors are not ordered in C++. Vector elements are placed in adjacent storage and  can be easily accessed and traversed across using iterators. In vectors, data is inserted at the end when we use push_back() function . Inserting an element at the end of a vector takes differential time, as sometimes there may be a need of extending the vector,  but inserting the element at the beginning or at the middle takes linear time. Removing the last element takes only constant time because no resizing takes place. Check out this free online C++ tutorial to learn more and enhance your skills.


THIS ARTICLE WAS TAKEN FROM & CAN BE FOUND HERE: https://www.mygreatlearning.com/blog/vectors-in-c/#:~:text=Vectors%20in%20C%2B%2B%20are%20sequence,regular%20pointers%20to%20its%20elements.


Basic Vector Concepts
----

An example of how Vectors are made, elements are pushed back and cleared
