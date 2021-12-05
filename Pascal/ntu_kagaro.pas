var n,i,a,b,d:longint;

begin
//assign(input,'ntu_kagaro.inp');reset(input);
readln(n,a,b);
if n mod b=0 then
    begin
    writeln(n div b);
    halt;
    end;
for i:=n div b downto 1 do
    if (n-b*i) mod a=0 then
        begin
        writeln(i+(n-b*i) div a);
        halt;
        end;
if n mod a=0 then
    writeln(n div a)
else
    writeln(-1);
end.