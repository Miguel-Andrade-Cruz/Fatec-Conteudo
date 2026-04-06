
def group_records(qs):

    records_grouped = {}
    for row in qs:

        acc_info = (row["acc__code"], row["acc__label"])
        segm_info = (row["segm__code"], row["segm__label"])

        records_grouped \
            .setdefault(acc_info, {}) \
            .setdefault(segm_info, []) \
            .append(
                (row["niche__code"], row["niche__label"])
            )

    return records_grouped
