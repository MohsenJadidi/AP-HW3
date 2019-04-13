

CREATE TABLE "User"(
    id SERIAL,
    telegram_id VARCHAR(255) NOT NULL,
    phone VARCHAR(16) NOT NULL,
    email VARCHAR(128) NOT NULL,
    password VARCHAR(255) NOT NULL,
    first_name VARCHAR(64) NOT NULL,
    last_name VARCHAR(64) NOT NULL,
    verification_code VARCHAR(255) NOT NULL,
    profile_picture_url VARCHAR(255) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,

    PRIMARY KEY(id)
);

CREATE TABLE BlockUser(
    blocker_user_id INTEGER NOT NULL,
    blocked_user_id INTEGER NOT NULL,
    created_at TIMESTAMP NOT NULL,

    PRIMARY KEY (blocker_user_id, blocked_user_id),
    FOREIGN KEY (blocker_user_id) REFERENCES "User"(id),
    FOREIGN KEY (blocked_user_id) REFERENCES "User"(id)

);


CREATE TABLE "Message"(
    id SERIAL,
    sender_id INTEGER NOT NULL,
    receiver_id INTEGER NOT NULL,
    message_type VARCHAR(32) NOT NULL,
    message_text VARCHAR(255) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,

    CHECK (message_type IN ('audio', 'video', 'image', 'text')),
    
    PRIMARY KEY(id),
    FOREIGN KEY (sender_id) REFERENCES "User"(id),
    FOREIGN KEY (receiver_id) REFERENCES "User"(id)

);

CREATE TABLE Channel(
    id SERIAL,
    telegram_id VARCHAR(255) NOT NULL,
    title VARCHAR(64) NOT NULL,
    info VARCHAR(128) NOT NULL,
    creator_id INTEGER NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,

    PRIMARY KEY (id),
    FOREIGN KEY (creator_id) REFERENCES "User"(id)

); 

CREATE TABLE "Group"(
    id SERIAL,
    creator_id INTEGER NOT NULL,
    title VARCHAR(64) NOT NULL,
    join_url VARCHAR(255) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,

    PRIMARY KEY (id),
    FOREIGN KEY (creator_id) REFERENCES "User"(id)

);

CREATE TABLE GroupMessage(
    id SERIAL,
    group_id INTEGER NOT NULL,
    sender_id INTEGER NOT NULL,
    message_type VARCHAR(255) NOT NULL,
    message_text VARCHAR(1024) NOT NULL,
    created_at TIMESTAMP NOT NULL,
    updated_at TIMESTAMP NOT NULL,

    CHECK (message_type IN ('audio', 'video', 'image', 'text')),
    
    PRIMARY KEY (id),
    FOREIGN KEY (group_id) REFERENCES "Group"(id),
    FOREIGN KEY (sender_id) REFERENCES "User"(id)

);

CREATE TABLE ChannelMessage (
	id SERIAL,
	channel_id INTEGER NOT NULL,
	message_type VARCHAR(255) NOT NULL,
	message_text VARCHAR(1024) NOT NULL,
	created_at TIMESTAMP NOT NULL,
	updated_at TIMESTAMP NOT NULL,

    CHECK (message_type IN ('audio', 'video', 'image', 'text')),
    
    PRIMARY KEY (id),
	FOREIGN KEY (channel_id) REFERENCES Channel(id)
);

CREATE TABLE MessageAttachment (
	message_id INTEGER NOT NULL,
	attachment_url VARCHAR(255) NOT NULL,
	attachment_thumb_url VARCHAR(255) NOT NULL,

	PRIMARY KEY (message_id, attachment_url, attachment_thumb_url),
	FOREIGN KEY (message_id) REFERENCES GroupMessage(id)
);

CREATE TABLE GroupMessageAttachment (
	message_id INTEGER NOT NULL,
	attachment_url VARCHAR(255) NOT NULL,
	attachment_thumb_url VARCHAR(255) NOT NULL,

	PRIMARY KEY (message_id, attachment_url, attachment_thumb_url),
	FOREIGN KEY (message_id) REFERENCES GroupMessage(id)
);

CREATE TABLE ChannelMessageAttachment (
	message_id INTEGER NOT NULL,
	attachment_url VARCHAR(255) NOT NULL,
	attachment_thumb_url VARCHAR(255) NOT NULL,

	PRIMARY KEY (message_id, attachment_url, attachment_thumb_url),
	FOREIGN KEY (message_id) REFERENCES ChannelMessage(id)
);

CREATE TABLE ChannelMembership(
	user_id INTEGER NOT NULL,
	channel_id INTEGER NOT NULL,
	created_at TIMESTAMP NOT NULL,

	PRIMARY KEY (user_id, channel_id),
	FOREIGN KEY (user_id) REFERENCES "User"(id),
	FOREIGN KEY (channel_id) REFERENCES Channel(id)
);

CREATE TABLE GroupMembership (
	user_id INTEGER NOT NULL,
	group_id INTEGER NOT NULL,
	created_at TIMESTAMP NOT NULL,

    PRIMARY KEY (user_id, group_id),
	FOREIGN KEY (user_id) REFERENCES "User"(id),
	FOREIGN KEY (group_id) REFERENCES "Group"(id)
);