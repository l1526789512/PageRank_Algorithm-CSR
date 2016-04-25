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
    
    for i = 1: r
        
        fprintf( fid,'%d,%d,%f\n', data_dump(i, 1), data_dump(i, 2), data_dump(i, 3));
    end
    
    %fprintf(fid2, 'URLs\n');
    
    [x, ~] = size(names);
    
    for i = 1: x
    
       fprintf(fid2, '%s\n', names{i, 1}); 
    end

    fclose all;
    
end