# Crab (not real title)
This game is a mecha space game where you are in mars which is your home but it is getting overrun by a lot of space
crabs.


## General Ideas
The game should make mechas look kinda heroic while looking down on less human like forms of weapon. This is because
the mecha is a form of tool which extends human capabilities and makes them more superior. On the other hand more
computer controlled or unhuman kinds of weapon are not really an extension of the human and are more like making a
a slave to it's workings and are therefore gay.

For example in ancient times people had to run around with spears and shit hunting for animals but now they sit around
telling alexa to feed food into their mouths. Therefore the progress of technology is not inherently a good thing and
that is because technology falls into two categories: "tools" and "machines (or think of better word)". Tools are an
extension of the humans themselves and therefore their progress makes humans become more superior, while machines do the
oppsite, and for every piece of progress in the world of machines, humans have become more contemptible to even it out.

The space crabs are in fact themselves humans that have been degraded into some kind of pest species with chemicals
and reverse evolution.

Another good example is that the earth people's war machines and mechas will have "personality" and be personified in
themselves, whereas ones that are built on mars will not do that. Like how these fucking stupid windows and mac
computers start talking to you and saying bullshit when you boot them up for the first time like I just heard.


## Code Style
### formatting
Formatting is simple and fairly self explanatory. Will expand on that later if really needed. Docstring all arguments
and classes and things.

Everything should be in a class.

### Files
All subtypes are implemented in header file only, and should have their own special folder, while other types must have
both a .cc and .hh. One single subtype can also have multiple folders, for example menus and widgets which are both
just subtypes of widgets.

You do not need to make a menu class for every little detail so do not bother doing that as it's a waste of space when
you can just set the widgets up within the scene class.


## Gameplay
### Time
I want the time taken to perform a given action to be very clear and I want every action to have an associated time
taken. This will be measured in "cycles". In order to save screen space I will just add a little clock icon or sometihng
and then a non decimal number. I will make the default number of cycles like 6 or something so that fractions are not
needed.

When you "look" at an enemy you should also be able to see how many cycles it takes them to perform actions like walking
and attacking and carrying out the special attacks that they are likely to carry out.

Since you are in a mecha, there is a lot of equipment that you can change, but all of it will take a reasonable amount
of time to do so, so it is not something you could do in the middle of a battle.

### Attacks
I would like it if many of the more powerful weapons and attacks can not be "aimed" in the conventional way that ranged
weapons are aimed in roguelikes. Instead, it should be more like a game of chess where you must position yourself and
your enemies so that the attack will hit them. For example there may be an attack that fires a lazer in the four
cardinal directions at once, or maybe you can only fire a given weapon in a single cardinal direction.

This rule is not legally binding however, so some attacks can still be aimed directly at enemies, but maybe they will
not be as strong, or have limited range or whatever. Also I am gonna try this out and if it sucks I will just drop it.

One potential danger is that if enemies are pathfinding to get line of sight to the player to shoot him and can only
shoot in a few directions they will all start stepping in front of each other which will kind of fuck that up. Oh
but you wouldn't generally have many enemies doing that kind of attack in the same place.

Also, I will make it that it shows you a red indictor of all attacks you were hit by since your last turn so you
can see where these attacks are coming from.

### Levelling
Since you are in a mech it does not make much sense for you to level up IMO. However, a roguelike without levelling
would be quite gay, so I must figure out a way to make you level up. Ok yeah as you kill more enemies you will gain
will power which will make you more powerful in some way or other. Other than that you will need to keep getting
new mech chassises and weapons and shit to get more powere.

### Improvisation
One very fun aspect of roguelikes is when you are stuck in a very bad situation and forced to use every random piece of
junk in your inventory in an attempt to make some kind of escape plan. I would like to create these kinds of situations
in the game by having a lot of funny different items that you can end up with that may explode or do something else if
hurled or ignited or activated.


## Artistic Style
Stylistically the game should be minimalistic in such a way that it leads the player to not view the game as what they
are seeing, but that what they are seeing is just a "diagram" which allows their imagination to understand what is
happening. Putting in good atmospheric text things and stuff are good, and so is adding some cool music, but overall it
should be aiming to do things in such a way that it provides food for the player's imagination rather than conflicting
with it.

IMO this is one of the main reasons that text based roguelikes are generally the best kind, though I am ok with using
text like symbols since it is basically the same thing.

Also, there will be a built in text font, but if users want to provide their own they will also be able to do that.
