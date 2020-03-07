function epsilon = myeps()
  epsilon = 1;
  while (1 + epsilon ~= 1)
    epsilon /= 2;
  end
  epsilon = 2 * epsilon;
 

 