function SaveTestCase(data, names, save_name)
   
    [i,j,val] = find(data);
    data_dump = [i, j, val];
    %data = spconvert( data_dump );
    %save -ascii data.txt data_dump
    fid = fopen(sprintf('C:\\Users\\nrenh_000\\OneDrive for Business\\Semester 2\\CSCI 2270\\Renninger_CSCI2270_FinalProject\\Test_Cases\\%s.txt', save_name), 'wt');
    fid2 = fopen(sprintf('C:\\Users\\nrenh_000\\OneDrive for Business\\Semester 2\\CSCI 2270\\Renninger_CSCI2270_FinalProject\\Test_Cases\\%s_urls.txt', save_name), 'wt');
    
    [r, ~] = size(data_dump);
    [sizeOfGraph, ~] = size(data);
    
    fprintf(fid, '%d\n', sizeOfGraph);
    
    currentRow = data_dump(1,1);
    i = 1;
    rowIndex = 1;
    hasNotBeenUsed = boolean(ones(1, r));
    count = 0;
    
    while i <= r
        
        if data_dump(i,1) == currentRow && hasNotBeenUsed(1, i)
        
            fprintf(fid, '%d,%d,%f\n', data_dump(i, 1), data_dump(i, 2), data_dump(i, 3));
            hasNotBeenUsed(1, i) = false;
            count = count + 1;
            
        elseif i == r 
            
            currentRow = data_dump(rowIndex + 1, 1);
            rowIndex = rowIndex + 1;
            i = 0;
        end
        
        i = i + 1;
        
    end
    
    %fprintf(fid2, 'URLs\n');
    
    [x, ~] = size(names);
    
    for i = 1: x
    
       fprintf(fid2, '%s\n', names{i, 1}); 
    end

    fclose all;
    
end