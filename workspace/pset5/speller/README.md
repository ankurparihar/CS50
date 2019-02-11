# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It's a lung disease caused by inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

 getrusage returns resource usage measures for

## Per that same man page, how many members are in a variable of type `struct rusage`?

14

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

If we do not pass by reference then the `before` and `after` structs are copied to `calculate` parameters,
which results in time consumption. So by passing by reference we reduce that extra time.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

We start to scan the file character by character. We allow only alphabetical characters and apostrophes.
As long as the scanning goes and the word length is maximum equal to defined `LENGTH` we store characters
in a char array called `word`. If the word length goes beyond maximum allowed we discard that word and
after consuming all the characters of that word reset the index so that the next scan characters can be
stored. If it's digit we also discard that and reset index. So the `space` and `\n` also resets the index
indicating the presence of new word until we encounter an `EOF`.
Then if the index in a natural number then it means that we have captured a word successfully and now it's
time to operate upon it.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

`fscanf` reads string of all type. It doesn't ignore the alphanumeric of special characters. So if we use
`fscanf` we have to again check for these condition in scanned string which results in double amount of work.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

To clarify that the parameters are immutable.
