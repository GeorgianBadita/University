def read_data(in_file):

    with open(in_file, "r") as f:
        x_ = []
        y_ = []
        num_feat = int(f.readline().strip())
        num_ex = int(f.readline().strip())
        for _ in range(num_ex):
            line = f.readline().split(",")
            y_row = []
            x_row = []
            for i in range(len(line)):
                if i != len(line) - 1:
                    x_row.append(float(line[i]))
                else:
                    y_row.append(float(line[i]))
            x_.append(x_row)
            y_.append(y_row)
    return x_, y_, num_feat - 1
