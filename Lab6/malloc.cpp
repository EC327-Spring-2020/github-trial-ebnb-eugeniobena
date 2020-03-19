#include <stdio.h>
#include <stdlib.h>

//What are we doing here? Please explain as a comment. 
// We are creating a function with a pointer that points to a variable on the heap, since the keyword new is added.
void ec327_lab6() {

	int *stay_safe = new int(20);
	return;
}

//What is wrong here?
//memory is allocated of size 20 bytes, this is done on the heap and is never deleted to its a memory leak
int main(){
  	int counter;
  	int *ptr;

	// malloc? malloc is a fucntion that allocates a block of memory specified by the user in bytes and returns a pointer to the beginning of the block
  	for (counter=0; counter < 13; counter++){
  		ptr = (int *)malloc(sizeof(int) * 47);
  	}
	ec327_lab6();	
  	free(ptr); //im not sure but I think this leads to a dangling pointer.
  	return 0;
}
