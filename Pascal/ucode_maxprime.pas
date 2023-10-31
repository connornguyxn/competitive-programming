type ntoar=array[1..1000000] of boolean;
var a,i:longint;
nto:ntoar;
//////////////////////////////////////////
procedure sangnto(var a:ntoar);
var i,j:longint;
    begin
    fillchar(a,sizeof(a),true);
    a[1]:=false;
    i:=2;
    while i<=trunc(sqrt(1000000)) do
        begin
        while a[i]=false do
            i:=i+1;
        for j:=2 to 1000000 div i do
            a[i*j]:=false;
        i:=i+1;
        end;
    end;
/////////////////////////////////////////
begin
assign(input,'ucode_maxprime.inp');reset(input);
assign(output,'ucode_maxprime.out');rewrite(output);
readln(a);
sangnto(nto);
for i:=a-1 downto 1 do
    if nto[i]=true then
        begin
        writeln(i);
        halt;
        end;
end.