	.name "Small Bytes"
	.comment "They are afraid of women or women are afraid of them (they prefer to code)."

start:
    ld      %50, r9
    ld      %24, r7
    ld      %23, r8
    ld      %265, r10
    sti r1, %:looplive %1
    sti     r1 %:attack_back %1
    sti     r1 %:attack_front %1
    fork %:looplive
    fork %:attack_back
    fork %:attack_front

looplive:
    live %1
    fork %:looplive
	ld %0, r3
    zjmp %:looplive

attack_front:
    live %1234
    add     r11, r15, r11
    sti     r7, r10, r11
    sti     r8, r10, r11
    ld      %0, r16
    zjmp    %:attack_front

attack_back:
    live %1234
    sub     r13, r15, r13
    sti     r9, r10, r13
    ld      %0, r16
    zjmp    %:attack_back