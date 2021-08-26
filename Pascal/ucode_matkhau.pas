var a,b:ansistring;
num:ansistring='0123456789';
i,kt:longint;
kq,bs:qword;
//////////////////////////////////////////

//////////////////////////////////////////
begin
//assign(input,'ucode_matkhau.inp');reset(input);
//assign(output,'ucode_matkhau.out');rewrite(output);
readln(a);
kq:=1;
for i:=1 to length(a) do
    begin
    if pos(a[i],num)<>0 then
        b:=b+a[i]
    else
        if length(b)<>0 then
            begin
            val(b,bs,kt);
            kq:=((kq mod 1000000007)*(bs mod 1000000007)) mod 1000000007;
            b:='';
            end;
    end;
writeln(kq mod 1000000007);
end.
