function snto(a:longint):boolean;
begin
if a<23 then exit(false);
while nto(a) do
    a:=a div 10;
snto:=a=0;
end;