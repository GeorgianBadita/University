def parse_table_from_file(in_file):
    res = {}
    with open(in_file, "r") as f:
        line = f.readline().strip()
        while line != "":
            elems = line.split(":")
            if elems[0] != "ATOM":
                res[elems[0]] = elems[1]
            line = f.readline().strip()
    return res
