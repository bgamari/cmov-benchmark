.globl fib
fib:
  test   %edi,%edi
  jle    end
  lea    -0x1(%rdi),%eax
  lea    0x8(,%rax,8),%r8

  mov    $0x0,%eax
loop:
  mov    (%rdx,%rax,1),%rdi
  cmp    %rdi,(%rsi,%rax,1)
  jg     cont
  mov    (%rsi,%rax,1),%rdi
cont:
  mov    %rdi,(%rcx,%rax,1)
  add    $0x8,%rax
  cmp    %r8,%rax
  jne    loop
end:
  repz retq 

