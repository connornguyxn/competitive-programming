//coded w/ <3 by inf1nity
var a,b:string;
    i,j:longint;
////////////
begin
readln(a);
b:='';
for i:=1 to length(a)-1 do
    for j:=i+1 to length(a) do
        if a[i]=a[j] then
            b:=b+a[i];
for i:=1 to length(a) do
    if pos(a[i],b)=0 then
        write(a[i]);
end.