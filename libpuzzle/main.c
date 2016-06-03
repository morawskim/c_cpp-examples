#include <stdio.h>
#include <stdlib.h>
#include "puzzle.h"

int main(int argc, char *argv[]) {
    PuzzleContext context;
    PuzzleCvec cvec1, cvec2;
    double d;

    if (argc != 3) {
        fprintf(stderr, "Wrong number of arguments.\n");
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "%s file1 file2", argv[0]);
        fprintf(stderr, "\n");
        return 1;
    }

    const char *file1 = argv[1];
    const char *file2 = argv[2];

    puzzle_init_context(&context);
    puzzle_init_cvec(&context, &cvec1);
    puzzle_init_cvec(&context, &cvec2);
    if (puzzle_fill_cvec_from_file(&context, &cvec1, file1) != 0) {
        fprintf(stderr, "Unable to read %s\n", file1);
        return 1;
    }
    if (puzzle_fill_cvec_from_file(&context, &cvec2, file2) != 0) {
        fprintf(stderr, "Unable to read %s\n", file2);
        return 1;
    }
    d = puzzle_vector_normalized_distance(&context, &cvec1, &cvec2, 1);
    fprintf(stdout, "Distance: %f\n", d);
    puzzle_free_cvec(&context, &cvec1);
    puzzle_free_cvec(&context, &cvec2);
    puzzle_free_context(&context);

    return EXIT_SUCCESS;
}