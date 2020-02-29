#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "packer.h"

#include "argtable3.h"
#include "log.h"

struct arg_lit *verb, *help, *version;
struct arg_str *cipher, *packing_method;
struct arg_file *output, *file;
struct arg_end *end;

void display_argtable_help(char *progname, void **argtable) {
    printf("Usage: %s", progname);
    arg_print_syntax(stdout, argtable, "\n");
    arg_print_glossary(stdout, argtable, "  %-25s %s\n");
    exit(0);
}

int main(int argc, char** argv) {
        void *argtable[] = {
                help     = arg_litn("h", "help", 0, 1, "Display this help and exit"),
                version  = arg_litn("V", "version", 0, 1, "Display version info and exit"),
                verb     = arg_litn("v", "verbose", 0, 1, "Verbose output"),
                file     = arg_filen("f", "file", "file", 0, 1, "File to pack"),
                cipher   = arg_strn("c", "cipher", "<xor>", 0, 1, "Cipher method to use"),
                packing_method = arg_strn("m", "method", "<section_insertion, code_cave, silvio_infection>", 0, 1, "Method to pack the binary"),
                output   = arg_filen("o", "output", "file", 0, 1, "Output file"),
                end      = arg_end(20),
        };

        char *progname = "Silent_Crypt";
        char *progversion = "0.1";
        char *progdate = "2020";
        char *author_name = "SilentVoid";

        output->filename[0] = NULL;
        file->filename[0] = NULL;
        cipher->sval[0] = NULL;
        packing_method->sval[0] = NULL;

        int nerrors;
        nerrors = arg_parse(argc, argv, argtable);

        verbose = verb->count;

        if(help->count > 0) {
            display_argtable_help(progname, argtable);
        }

        if(version->count > 0) {
                printf("%s %s\n", progname, progversion);
                printf("Copyright (C) %s %s\n", progdate, author_name);
                exit(0);
        }

        if(nerrors > 0) {
                arg_print_errors(stdout, end, progname);
                printf("Try '%s --help' for more informations.\n", progname);
                exit(1);
        }

        if(file->count > 0 && cipher->count > 0 && packing_method->count > 0) {
            if(
                    (strcmp(cipher->sval[0], "xor") != 0) &&
                    (strcmp(cipher->sval[0], "aes") != 0)
            ) {
                log_error("Wrong cipher method");
                display_argtable_help(progname, argtable);
            }

            if(
                    (strcmp(packing_method->sval[0], "silvio_infection") != 0) &&
                    (strcmp(packing_method->sval[0], "code_cave") != 0) &&
                    (strcmp(packing_method->sval[0], "section_insertion") != 0)
            ) {
                log_error("Wrong packing method");
                display_argtable_help(progname, argtable);
            }

            pack_file((char *) file->filename[0], (char *) cipher->sval[0], (char *) packing_method->sval[0], (char *) output->filename[0]);
        }
        else {
            display_argtable_help(progname, argtable);
        }



        arg_freetable(argtable, sizeof(argtable) / sizeof(argtable[0]));
        return 0;
}
