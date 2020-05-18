function yy=eval_node_pol(puncte, noduri)
  yy = ones(size(puncte));
  n = length(noduri);  
  for j=1:n
    yy = yy.*(puncte - noduri(j)); 
  end
end