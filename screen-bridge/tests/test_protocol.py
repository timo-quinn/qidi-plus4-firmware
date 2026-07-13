import pytest

from qidi_screen_bridge.protocol import (
    EventKind,
    PacketFramer,
    decode_packet,
    encode_command,
    quote_text,
)


def test_framer_handles_fragmented_and_consecutive_packets():
    framer = PacketFramer()
    assert framer.feed(b"\x65\x01") == []
    assert framer.feed(b"\x02\x01\xff\xff\xff\x66\x03\xff\xff\xff") == [
        b"\x65\x01\x02\x01",
        b"\x66\x03",
    ]


def test_decode_touch_packet():
    event = decode_packet(b"\x65\x04\x09\x01\xff\xff\xff")
    assert event.kind is EventKind.TOUCH
    assert (event.page_id, event.component_id, event.pressed) == (4, 9, True)


def test_decode_numeric_packet_is_little_endian():
    event = decode_packet(b"\x71\x78\x56\x34\x12")
    assert event.kind is EventKind.NUMBER
    assert event.value == 0x12345678


def test_encode_command_and_text_reject_unsafe_boundaries():
    assert encode_command("page 1") == b"page 1\xff\xff\xff"
    assert quote_text("PLA") == '"PLA"'
    with pytest.raises(ValueError):
        encode_command("page 1\n")
    with pytest.raises(ValueError):
        quote_text('bad"value')
