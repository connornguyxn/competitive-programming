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
end.