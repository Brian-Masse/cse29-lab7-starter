#include "jstr.c"


// This one has a subtle bug. There isn't really a one-line fix for this,
// but can you use valgrind to figure out the issue?
String substring2(String s, int start, int end) {
    assert(start >= 0);
    assert(end <= s.length);
    assert(start <= end);
    
	int new_length = end - start;

    // Make a copy of s.contents for us to substringify
    char* s_copy = malloc(new_length + 1);
    strcpy(s_copy, s.contents + start);


    // Terminate our copy at index `end`
    s_copy[new_length - 1] = 0;

    String r = { new_length, s_copy };
    return r;
}

int main() {
    
    String abcdef2 = new_String("abcdef");
    String def2 = substring2(abcdef2, 3, 6);
    printf("%s\n", def2.contents);
    free(def2.contents);
    free(abcdef2.contents);
}
