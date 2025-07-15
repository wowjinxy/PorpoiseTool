
def format_hex(num: int) -> str:
    """Return hex representation with sign for negative numbers."""
    return f"-0x{-num:X}" if num < 0 else f"0x{num:X}"

