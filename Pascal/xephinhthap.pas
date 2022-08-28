var n:qword;

begin
assign(input,'thap.inp');reset(input);
assign(output,'thap.out');rewrite(output);
readln(n);
writeln((n+1)*n div 2);
end.
