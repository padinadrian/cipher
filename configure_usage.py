#!/usr/bin/env python
import sys

if __name__ == "__main__":
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    with open(output_file, 'wb') as outfile:
        outfile.write("// Include this file to import the usage info as a string.\n")
        outfile.write("static const char usage_str[] = \"\\\n")
        for line in open(input_file, 'rb'):
            outfile.write(line.rstrip())
            outfile.write("\\n\\\n")
        outfile.write("\";\n")