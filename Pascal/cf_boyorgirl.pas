var a,b:ansistring;
i,d:longint;

begin
assign(input,'codeforces_boyorgirl.inp');reset(input);
assign(output,'codeforces_boyorgirl.out');rewrite(output);
readln(a);
for i:=1 to length(a) do
    if pos(a[i],copy(a,i+1,length(a)-i))=0 then
        d:=d+1;
if d mod 2=0 then
    writeln('CHAT WITH HER!')
else
    writeln('IGNORE HIM!');
end.