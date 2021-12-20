var n,m,y,x,k:qword;
////////////////////////////////////// 
begin
readln(n,m,y,x,k);
x:=(x+k-1) mod (2*(m-1))+1;
y:=(y+k-1) mod (2*(n-1))+1;
if x>m then 
    begin
    x:=2*m-x;
    end;
if y>n then 
    begin
    y:=2*n-y;
    end;
writeln(y,' ',x);
end.