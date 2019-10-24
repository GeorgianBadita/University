import numpy as np

from gradient_descent.gradient_descent import solve_gradient_descent
from gradient_descent.gradient_descent_statistics import plot_cost, get_gd_statistics
from least_squares.least_squares import solve_least_squares
from least_squares.least_squares_statistics import get_statistics
from utils.read_data import get_features_from_file, get_test_data, get_result_matrix, get_properties, get_training_data

"====================================================="
features = get_features_from_file("data/Concrete_Data.xls")  # all features except the result
result = get_result_matrix("data/Concrete_Data.xls")  # the result set
training_features = get_training_data(features)  # 80% of features (for training)
result_features = get_training_data(result)  # 80% of results (for training)
test_features = get_test_data(features)  # 20% of features (for test)
result_test = get_test_data(result)  # 20% of results (for test)
"====================================================="

"====================================================="
props = get_properties("props/config.txt")
alg_type = props['method']
plt_size = int(props['plt_size'])
epochs = int(props['gd_epochs'])
diff_cost = float(props['diff_cost'])
learning_rate = float(props['learning_rate'])
"====================================================="

if alg_type == "LEAST_SQUARES\n":
    coeffs = solve_least_squares(training_features, result_features)
    print("Mean squared error for least squares method: " + str(get_statistics(coeffs, test_features, result_test)))
    print("Least squared coefficients calculated: " + str(coeffs))
else:
    res = solve_gradient_descent(training_features, result_features, learning_rate, diff_cost, epochs)
    coeffs = res[0]
    costs = res[1]
    # print(costs[-1])
    print(
        "Mean squared error for gradient descent method: " + str(get_gd_statistics(coeffs, test_features, result_test)))
    print("Gradient descent coefficients calculated: " + str(coeffs))
    plot_cost(costs, plt_size)
