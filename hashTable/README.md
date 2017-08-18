# Different types of hash tables

This folder hosts two different strategies to collision handling: Open Addressing and 'Buckets'

Open Addressing (in hashTableOA.h) uses linear probing to handle collisions, allowing entries to have multiple possible locations. Knowing this, the hash function h(k,i) = (k mod m) + i for some key k.

The Bucket strategy (in hashTableCH.h) uses chaining to handle collisions, where multiple entries may exist in the same location (0 or more KVPs). As far as the bucket strategy goes, you can actually use any ADT to store the KVPs in the same 'bucket', but for simplicity sake linked lists are used. The temptation to use the open addressing hash table instead was, however, very tempting.

