type ntoar=array[1..1000000] of boolean;
var nto:ntoar;
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
////////////////////////////////////////////
begin
assign(input,'sangnto.inp');reset(input);
assign(output,'sangnto.out');rewrite(output);
sangnto(nto);
writeln(nto[2])
end.
