.include "/home/madhur/m328Pdef.inc"
sbi DDRB, 5    ; Set PB5 (Arduino Uno onboard LED) as output
cbi PORTB, 5   ; Turn LED off initially
; Clear upper registers so we can safely use LDI
clr r16 
clr r17
clr r18
; Load initial values into upper registers safely
ldi r16, 0b00000001
mov r1, r16           ; r1 = 1
ldi r17, 0b00000000
mov r2, r17           ; r2 = 0
ldi r18, 0b00000001   ; r18 = 1
lq:
    mov r3, r18       ; Save r18 into r3
    and r16, r17      ; r16 = r16 AND r17
    and r17, r18      ; r17 = r17 AND r18
    and r18, r1       ; r18 = r18 AND r1
    or r16, r17       ; r16 = r16 OR r17
    
    ; The last operation before the branch determines the Zero Flag status
    or r16, r18       ; r16 = r16 OR r18
    
    ;this evaluates to 1, meaning Z=0. 
    
    breq lq           
sbi PORTB, 5   ; This turns on the LED on Pin 13 once the loop exits
start:
    rjmp start ; Infinite loop to halt the microcontroller
