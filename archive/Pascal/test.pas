<<<<<<< HEAD
var i,cnt:longint;
    s:ansistring;

begin
readln(s);
cnt := 0;
for i := 1 to length(s) do
    begin
    if (s[i] = ' ') then
        cnt := cnt + 1;
    end;
writeln(cnt + 1);
=======
var a,tmp:ansistring;
    i,md:longint;
///////////////////////////////////////
begin
readln(a);
md := 0;
while (length(a) > 1) do
    begin
    tmp := '';
    for i := 1 to length(a) do
        begin
        if (i mod 2 <> md) then
            tmp := tmp + a[i];
        end;
    md := (md + 1) mod 2;
    a := tmp;
    end;
writeln(a);
>>>>>>> ff1e4424a3963b8bde9665cede1359df7d8c8746
end.