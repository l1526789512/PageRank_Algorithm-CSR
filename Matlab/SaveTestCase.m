function SaveTestCase(data, names, save_name)
   
    [i,j,val] = find(data);
    data_dump = [i, j, val];
    %data = spconvert( data_dump );
    %save -ascii data.txt data_dump
    fid = fopen(sprintf('%s', save_name), 'wt');
    
    [r, ~] = size(data_dump);
    
    for i = 1: r
        
        fprintf( fid,'%d,%d,%f\n', data_dump(i, 1), data_dump(i, 2), data_dump(i, 3));
    end
    
    fprintf(fid, 'URLs\n');
    
    [x, ~] = size(names);
    
    for i = 1: x
    
       fprintf(fid, '%s\n', names{i, 1}); 
    end

    fclose(fid);
    
end