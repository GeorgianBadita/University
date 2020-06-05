function T = sparse_teoplitz(col,row)

if nargin < 2  % symmetric case
  col(1) = conj(col(1)); row = col; col = conj(col); 
end

% Size of result.
m = length(col(:));  n = length(row(:));

% Locate the nonzero diagonals.
[ic,jc,sc] = find(col(:));
row(1) = 0;  % not used
[ir,jr,sr] = find(row(:));

% Use spdiags for construction.
d = [ ir-1; 1-ic ];
B = repmat( [ sr; sc ].', min(m,n),1 );
T = spdiags( B,d,m,n );