# PokerBot
poker ai in C++ converted in DLL to use in unity.


USE THE SHELL :

"quit" to end program.

"give" to put cards in bot hand by selecting the number and suit of the card.

"table" to put cards on the table by selecting the number and suit of the card.

"display" to see what's on the table and on the bot hand.

"nextGame" to pass on a phase.

"simulate" to simulate a play before the bot turn. You need to select your action, money bet and the original funds of the fake player.


List of RESPONSE (with id) sent by the bot, with an associated number :

CALL(1) : Bot called and bet money, number is what it has bet.

RAISE(2) : Bot raised and bet money, number is what is has bet.

FOLD(3) : Bot folded, it's turn must be avoided until a new round. Number is always 0 (a.k.a no bet).

CHECK(4) : Bot checked, number is always 0 (a.k.a no bet).

NOFUND(5) : Bot don't have funds anymore, it's turn must be avoided until he has money. Number is always 0 (a.k.a no bet).

ERROR(6) : Bot couldn't play, error code attached.



ERROR CODES :

1 : The previous play remembered by the bot was an 'ERROR' response with a code.

2 : Impossible 'last play remembered by the bot' cases*.

3 : The previous play remembered by the bot was a 'NOFUND' response; when given by a bot, this response must be skipped.



* : examples = (FOLD, 0) with 0 as total bet of the associated player / (CHECK, nbr > 0) / (CHECK, nbr) with 0 as total bet of the associated player / (RAISE, nbr <= 1) / (CALL, 0)