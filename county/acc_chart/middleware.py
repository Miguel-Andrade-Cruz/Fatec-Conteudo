from .models import Account, Niche, Segment


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




def pull_accounts():
    ACCOUNTS = {"new": "Criar conta"}

    qs = Account.objects.all().values()
    if qs.exists():
        ACCOUNTS.update(qs)
    return ACCOUNTS


def pull_segments():
    SEGMENTS = {"new": "Criar segmento"}

    qs = Segment.objects.all().values()
    if qs.exists():
        SEGMENTS.update(qs)
    return SEGMENTS


def pull_niches():
    NICHES = {"new": "Criar nicho"}

    qs = Niche.objects.all().values()
    if qs.exists():
        NICHES.update(qs)
    return NICHES


def handle_form_data(data):

    if data["accounts"] == "new":
        i_account = Account(label=data["new_account"])
        i_account.save()
        account_id = i_account.id
    else:
        account_id = data["accounts"]

    if data["segments"] == "new":
        i_segment = Segment(label=data["new_segment"])
        i_segment.save()
        segment_id = i_segment.id
    else:
        segment_id = data["segments"]

    if data["niches"] == "new":
        i_niche = Niche(label=data["new_niche"])
        i_niche.save()
        niche_id = i_niche.id
    else:
        niche_id = data["niches"]

    return (account_id, segment_id, niche_id)
