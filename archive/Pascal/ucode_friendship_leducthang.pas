var n,i,d,nho:longint; a:ansistring;
begin

readln(n);
for i:=1 to n do 

    begin
    readln(a);
    //nho:=length(a); d:=0;
    if pos('0',a)=0 then begin writeln('NO'); continue; end;
    if (a[1]='0') and (a[length(a)]='0') then 
    
        if (pos('1',a)<>0) then begin writeln('NO'); continue; end;
    while a[1]='1' do delete(a,1,1);
    while a[length(a)]='1' do delete(a,length(a),1);

    
    if pos('1',a)<>0 then begin writeln('NO'); continue; end 

        else begin writeln('YES'); continue; end;

    end;
end.

