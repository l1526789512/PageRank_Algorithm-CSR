function [Gin] = addStochasticElems(Gin, sizeOfGraph)

    [r, ~] = size(Gin);
    
    for i = 1:r
        
        numberOfNonZeroElems = nnz(Gin(:, i));
        
        if numberOfNonZeroElems == 0
           
           Gin(:, i) = 1/sizeOfGraph;
            
        end
        
    end
   

end